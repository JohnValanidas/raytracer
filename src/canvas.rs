use crate::tuple::Tuple;


#[cfg(test)]
#[path ="./tests/canvas.rs"] mod canvas;

pub struct Canvas {
    grid: Vec<Vec<Tuple>> 
}

impl Canvas {
    pub fn new(w: usize, h: usize) -> Canvas {
        return Canvas {grid: vec![vec![Tuple::color(0., 0., 0.); w]; h]};
    }
    pub fn write_pixel(&mut self, x: usize, y: usize, pixel: Tuple) {
        self.grid[x][y] = pixel; 
    }
}
