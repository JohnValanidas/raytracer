use crate::canvas::Canvas;
use crate::tuple::Tuple;

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_canvas() {
        let canvas = Canvas::new(20,40);
        assert_eq!(canvas.grid[0].len(), 40);
        assert_eq!(canvas.grid.len(), 20);

        for row in canvas.grid {
            for cell in row {
                assert_eq!(cell.x, 0.);
                assert_eq!(cell.y, 0.);
                assert_eq!(cell.z, 0.);
            }
        }
    }

    #[test]
    fn test_write_pixel() {
        let mut canvas = Canvas::new(20,20);
        let pixel  = Tuple::color(5.,4.,4.);
        canvas.write_pixel(4, 10, pixel);

        assert_eq!(canvas.grid[4][10], pixel);
    }
    #[test]
    fn test_ppm_file_header() {
        let canvas = Canvas::new(5,3);
        let data = canvas.create_ppm_header();
        assert_eq!("P3\n5 3\n255\n", data);
    }
    #[test]
    fn test_ppm_body() {
        let mut canvas = Canvas::new(5,3);
        let pixel1  = Tuple::color(1.5,0.,0.);
        let pixel2  = Tuple::color(0., 0.5,0.);
        let pixel3  = Tuple::color(-0.5,0.,1.);
        canvas.write_pixel(0, 0, pixel1);
        canvas.write_pixel(2, 1, pixel2);
        canvas.write_pixel(4, 2, pixel3);
        let data = canvas.create_ppm_body();
        assert_eq!("255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 127 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n", data);
    }
    #[test]
    fn test_ppm_body_ends_with_newline() {
        let canvas = Canvas::new(100,500);
        let data = canvas.create_ppm_body();
        println!("{}", data);
        assert_eq!('\n', data.chars().last().unwrap());
    }
}
