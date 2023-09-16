use crate::canvas::Canvas;
use crate::tuple::Tuple;

#[cfg(test)]
mod tests {
    use super::*;


    #[test]
    fn test_canvas() {
        let canvas = Canvas::new(20,40);
        assert_eq!(canvas.grid[0].len(), 20);
        assert_eq!(canvas.grid.len(), 40);

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
}
