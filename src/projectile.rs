use raytracer::tuple::Tuple;

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

pub fn main() {
    let mut proj = Projectile { position: Tuple::point(0., 0., 0.), velocity: Tuple::vector(100., 55., 10.)};
    let env = Envrionment {
        gravity: Tuple::vector(0., -9.8, 0.),
        wind: Tuple::vector(0., 0., 0.),
    };

    loop { 
        println!("Projectile is at position: x: {}, y: {}, z: {}", proj.position.x, proj.position.y, proj.velocity.z);
        proj = tick(&env, &proj);
        if proj.position.y <= 0.0f32 {
            break;
        }
    }  
}
