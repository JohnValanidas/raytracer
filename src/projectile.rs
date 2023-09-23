use raytracer::tuple::Tuple;
use raytracer::canvas::Canvas;

struct Projectile {
    position: Tuple,
    velocity: Tuple,
}

struct Envrionment {
    gravity: Tuple,
    wind: Tuple,
}

fn tick(env: &Envrionment, proj: &Projectile) -> Projectile {
    let position = proj.position + proj.velocity;
    let velocity = proj.velocity + env.gravity + env.wind;
    return Projectile {position: position, velocity: velocity};
}

fn write_proj_to_canvas(proj: &Projectile, canvas:&mut Canvas) {
    let x = proj.position.x as usize; 
    let y = canvas.height() - proj.position.y as usize;
    canvas.write_pixel(x, y, Tuple::color(1.0, 1.0, 1.0));
}

pub fn main() {
    let mut canvas = Canvas::new(900, 550);
    let mut proj = Projectile { position: Tuple::point(0., 1., 0.), velocity: Tuple::vector(1., 1.8, 0.) * 11.25};
    let env = Envrionment {
        gravity: Tuple::vector(0., -0.5, 0.),
        wind: Tuple::vector(-0.05, 0., 0.),
    };

    loop { 
        write_proj_to_canvas(&proj, &mut canvas);
        println!("Projectile is at position: x: {}, y: {}", proj.position.x, proj.position.y);
        proj = tick(&env, &proj);
        if proj.position.y <= 0.0f32 {
            break;
        }
    }  
    canvas.write_canvas_to_ppm_file("projectile.ppm");
}
