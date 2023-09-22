use crate::tuple::Tuple;
use std::fs::File;

#[cfg(test)]
#[path = "./tests/canvas.rs"]
mod canvas;

static PPM_VERSION: &str = "P3";
static MAX_COLOR_VALUE: u8 = 255;

pub struct Canvas {
    grid: Vec<Vec<Tuple>>,
}

impl Canvas {
    pub fn new(w: usize, h: usize) -> Canvas {
        return Canvas {
            grid: vec![vec![Tuple::color(0., 0., 0.); h]; w],
        };
    }

    pub fn write_pixel(&mut self, x: usize, y: usize, pixel: Tuple) {
        self.grid[x][y] = pixel;
    }

    pub fn write_canvas_to_ppm_file(&mut self, filename: &str) {
        let file_data = format!("{}{}", self.create_ppm_header(), self.create_ppm_body());
    }

    fn create_ppm_header(&self) -> String {
        let header = format!(
            "{}\n{} {}\n{}\n",
            PPM_VERSION,
            self.grid.len(),
            self.grid[0].len(),
            MAX_COLOR_VALUE
        );
        return header;
    }
    fn create_ppm_body(&self) -> String {
        let mut body: String = String::new();
        let mut cell_count: u16 = 0;
        for row in self.grid {
            for cell in row {
                cell_count += 1;
                let r = (cell.x * MAX_COLOR_VALUE as f32).clamp(0., MAX_COLOR_VALUE as f32) as u8;
                let g = (cell.y * MAX_COLOR_VALUE as f32).clamp(0., MAX_COLOR_VALUE as f32) as u8;
                let b = (cell.z * MAX_COLOR_VALUE as f32).clamp(0., MAX_COLOR_VALUE as f32) as u8;
                let data = format!("{} {} {}", r, g, b);
                body.push_str(&data.to_string());
                if cell_count != 0 && cell_count % 5 == 0 {
                    body.push('\n');
                } else {
                    body.push(' ');
                }
            }
        }
        if body.chars().last().unwrap() != '\n' {
            body.push('\n');
        }
        return body;
    }
}
