#[derive(PartialEq)]
pub enum TupleKind {
    Vector,
    Point
}


pub struct Tuple {
    pub x: f32,
    pub y: f32,
    pub z: f32,
    pub w: TupleKind, 
}

impl Tuple {
    fn point(x: f32, y: f32, z: f32) -> Tuple {
        return Tuple { x: x, y: y, z: z, w: TupleKind::Point }
    }

    fn vector(x: f32, y: f32, z: f32) -> Tuple {
        return Tuple { x: x, y: y, z: z, w: TupleKind::Vector }
    }
    fn is_point(&self) -> bool {
        return self.w == TupleKind::Point;
    }
    fn is_vector(&self) -> bool {
        return self.w == TupleKind::Vector;
    }
}

fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_is_point() {
        let point = Tuple::point(0.0, 0.0, 0.0);
        assert!(point.is_point());
    }

    #[test]
    fn test_is_vector() {
        let vector = Tuple::vector(0.0, 0.0, 0.0);
        assert!(vector.is_vector());
    }
}
