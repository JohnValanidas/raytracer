#[derive(Copy, Clone, PartialEq, Debug)]
pub enum TupleKind {
    Vector,
    Point
}

#[derive(Copy, Clone, Debug, PartialEq)]
pub struct Tuple {
    pub x: f32,
    pub y: f32,
    pub z: f32,
    pub w: TupleKind, 
}

use std::ops::Add;

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

impl Add for Tuple {
    type Output = Tuple;
    fn add(self, rhs: Self) -> Self::Output {
        return Tuple { x: self.x + rhs.x, y: self.y + rhs.y, z: self.z + rhs.z, w: self.w};
    }
}

fn main() {
    println!("Hello, world!");
    let point = Tuple::point(1.9,2.0,3.0);
    let secondPoint = Tuple::point(4.0, 3.0, 3.0);
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

    #[test]
    fn test_add_ensure_type() {
        let vector = Tuple::vector(0., 1., 2.);
        let point = Tuple::point(1., 1., 1.);

        let r1 = vector + point;
        let r2 = point + vector;
        
        assert!(r1.is_vector());
        assert!(r2.is_point());
    } 
    #[test]
    fn test_add() {
        let vector = Tuple::vector(0., 1., 2.);
        let point = Tuple::point(1., 1., 1.);

        let r1 = vector + point;
        
        assert_eq!(r1.x, 1.);
        assert_eq!(r1.y, 2.);
        assert_eq!(r1.z, 3.);
    } 
}
