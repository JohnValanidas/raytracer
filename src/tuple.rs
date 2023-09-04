
use std::ops::{ Add, Sub, Mul, Div, Not};

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


impl Tuple {
    pub fn point(x: f32, y: f32, z: f32) -> Tuple {
        return Tuple { x: x, y: y, z: z, w: TupleKind::Point }
    }

    pub fn vector(x: f32, y: f32, z: f32) -> Tuple {
        return Tuple { x: x, y: y, z: z, w: TupleKind::Vector }
    }
    pub fn is_point(&self) -> bool {
        return self.w == TupleKind::Point;
    }
    pub fn is_vector(&self) -> bool {
        return self.w == TupleKind::Vector;
    }
    pub fn magnitude(&self) -> f32 {
        if self.w == TupleKind::Vector {
            let intermediate = self.x.powi(2) + self.y.powi(2) + self.z.powi(2);
            return intermediate.sqrt(); 
        }
        return 0.0;
    }

    pub fn normalization(&self) -> Tuple {
        if self.w == TupleKind::Vector {
            let mag = self.magnitude();
            return Tuple { x: self.x / mag, y: self.y / mag, z: self.z / mag, w: self.w };
        }
        return self.clone();
    }

    pub fn dot_product(a: &Tuple, b: &Tuple) -> f32 {
        if a.w != TupleKind::Vector || b.w != TupleKind::Vector {
            panic!("Can't compute dot_product of a non vector");
        }
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    pub fn cross_product(a: &Tuple, b: &Tuple) -> Tuple {
        if a.w != TupleKind::Vector || b.w != TupleKind::Vector {
            panic!("Can't compute cross_product of a non vector");
        }
        return Tuple {x: a.y * b.z - a.z * b.y, y: a.z * b.x - a.x * b.z, z: a.x * b.y - a.y * b.x, w: TupleKind::Vector}
    }
}

impl Add for Tuple {
    type Output = Tuple;
    fn add(self, rhs: Self) -> Self::Output {
        return Tuple { x: self.x + rhs.x, y: self.y + rhs.y, z: self.z + rhs.z, w: self.w};
    }
}

impl Sub for Tuple {
    type Output = Tuple;
    fn sub(self, rhs: Self) -> Self::Output {
        return Tuple { x: self.x - rhs.x, y: self.y - rhs.y, z: self.z - rhs.z, w: self.w};
    }
}

impl Not for Tuple {
    type Output = Tuple;
    fn not(self) -> Self::Output {
        return Tuple { x: - self.x, y: -self.y, z: -self.z, w: self.w};
    }
}



impl Mul<f32> for Tuple {
    type Output = Tuple;
    fn mul(self, rhs: f32) -> Self::Output {
        return Tuple { x: self.x * rhs, y: self.y * rhs, z: self.z * rhs, w: self.w };
    }
}

impl Div<f32> for Tuple {
    type Output = Tuple;
    fn div(self, rhs: f32) -> Self::Output { 
        return Tuple { x: self.x / rhs, y: self.y / rhs, z: self.z / rhs, w: self.w };
    }
}

#[cfg(test)]
mod tests {
    use approx::relative_eq;

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

    #[test]
    fn test_sub_ensure_type() {
        let vector = Tuple::vector(0., 1., 2.);
        let point = Tuple::point(1., 1., 1.);

        let r1 = vector - point;
        let r2 = point - vector;
        
        assert!(r1.is_vector());
        assert!(r2.is_point());
    } 
    #[test]
    fn test_sub() {
        let vector = Tuple::vector(0., 1., 2.);
        let point = Tuple::point(1., 1., 1.);

        let r1 = vector - point;
        
        assert_eq!(r1.x, -1.);
        assert_eq!(r1.y, 0.);
        assert_eq!(r1.z, 1.);
    }

    #[test]
    fn test_mul_ensure_type() {
        let vector = Tuple::vector(0., 1., 2.);
        let point = Tuple::point(1., 1., 1.);

        let r1 = vector * 2.0;
        let r2 = point * 2.0;
        
        assert!(r1.is_vector());
        assert!(r2.is_point());
    } 
    #[test]
    fn test_mul() {
        let vector = Tuple::vector(0., 1., 2.);

        let r1 = vector * 3.;
        
        assert_eq!(r1.x, 0.);
        assert_eq!(r1.y, 3.);
        assert_eq!(r1.z, 6.);
    }
    

    #[test]
    fn test_div_ensure_type() {
        let vector = Tuple::vector(0., 1., 2.);
        let point = Tuple::point(1., 1., 1.);

        let r1 = vector / 2.0;
        let r2 = point / 2.0;
        
        assert!(r1.is_vector());
        assert!(r2.is_point());
    } 
    #[test]
    fn test_div() {
        let vector = Tuple::vector(0., 1., 2.);

        let r1 = vector / 0.5;
        
        assert_eq!(r1.x, 0.);
        assert_eq!(r1.y, 2.);
        assert_eq!(r1.z, 4.);
    }
    #[test]
    fn test_not_ensure_type() {
        let vector = Tuple::vector(0., 1., 2.);
        let point = Tuple::point(1., 1., 1.);

        let r1 = !vector;
        let r2 = !point;
        
        assert!(r1.is_vector());
        assert!(r2.is_point());
    } 
    #[test]
    fn test_not() {
        let vector = Tuple::vector(0., 1., 2.);

        let r1 = !vector; 
        
        assert_eq!(r1.x, 0.);
        assert_eq!(r1.y, -1.);
        assert_eq!(r1.z, -2.);
    }

    #[test]
    fn test_magnitude_vector() {
        let vector = Tuple::vector(10., 5., 5.);

        let mag = vector.magnitude();

        assert_eq!(mag, 150.0f32.sqrt());
    }
    #[test]
    fn test_magnitude_point() {
        let vector = Tuple::point(10., 5., 5.);

        let mag = vector.magnitude();

        assert_eq!(mag, 0f32.sqrt());
    }
    #[test]
    fn test_normalization_vector() {
        let vector = Tuple::vector(1., 2., 3.);

        let norm = vector.normalization();

        assert_eq!(norm.x, 1.0f32/14.0f32.sqrt());
        assert_eq!(norm.y, 2.0f32/14.0f32.sqrt());
        assert_eq!(norm.z, 3.0f32/14.0f32.sqrt());
    }

    #[test]
    fn test_mag_of_norm_vector() {
        let vector = Tuple::vector(10.,10., 10.);

        let norm = vector.normalization();

        let mag = norm.magnitude();

        relative_eq!(mag, 1.0f32);
    }

    #[test]
    fn test_normalization_point() {
        let vector = Tuple::point(10., 5., 5.);

        let norm = vector.normalization();

        assert_eq!(norm.x, 10.);
        assert_eq!(norm.y, 5.);
        assert_eq!(norm.z, 5.);
    }

    #[test]
    fn test_dot_product() {
        let vector1 = Tuple::vector(1., 2., 3.)                         ;
        let vector2 = Tuple::vector(2., 3., 4.);

        let dot_product = Tuple::dot_product(&vector1, &vector2);

        assert_eq!(dot_product, 20.0f32);
    }

    #[test]
    fn test_cross_product() {
        let vector1 = Tuple::vector(1., 2., 3.)                         ;
        let vector2 = Tuple::vector(2., 3., 4.);
    
        let cross_product = Tuple::cross_product(&vector1, &vector2);

        assert_eq!(cross_product.x, -1.);
        assert_eq!(cross_product.y, 2.);
        assert_eq!(cross_product.z, -1.);
    }
}
