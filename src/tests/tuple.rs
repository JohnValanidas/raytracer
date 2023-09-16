use crate::tuple::{Tuple, TupleKind};

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
        let vector1 = Tuple::vector(1., 2., 3.); 
        let vector2 = Tuple::vector(2., 3., 4.);

        let dot_product = Tuple::dot_product(&vector1, &vector2);

        assert_eq!(dot_product, 20.0f32);
    }

    #[test]
    fn test_cross_product() {
        let vector1 = Tuple::vector(1., 2., 3.);
        let vector2 = Tuple::vector(2., 3., 4.);
    
        let cross_product = Tuple::cross_product(&vector1, &vector2);

        assert_eq!(cross_product.x, -1.);
        assert_eq!(cross_product.y, 2.);
        assert_eq!(cross_product.z, -1.);
    }


    #[test]
    fn test_color_type() {
        let color = Tuple::color(1., 3., 3.);                         
        assert_eq!(color.w, TupleKind::Color);
    }

    #[test]
    fn test_color() {
        let color = Tuple::color(1., 3., 3.); 
        assert_eq!(color.x, 1.);
        assert_eq!(color.y, 3.);
        assert_eq!(color.z, 3.);
    }

    #[test]
    fn test_hadamard_product() {
        let color1 = Tuple::color(1., 3., 3.); 
        let color2 = Tuple::color(1., 3., 3.);
        let product = Tuple::hadamard_product(&color1, &color2);
        assert_eq!(product.x, 1.);
        assert_eq!(product.y, 9.);
        assert_eq!(product.z, 9.);
    }
}
