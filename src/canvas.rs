use crate::tuple::Tuple;
use std::io::prelude::*;
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
            grid: vec![vec![Tuple::color(0., 0., 0.); w]; h],
        };
    }
    pub fn height(&self) -> usize {
        return self.grid.len();
    }
    pub fn width(&self) -> usize {
        return self.grid[0].len();
    }

    pub fn write_pixel(&mut self, x: usize, y: usize, pixel: Tuple) {
        if x < 0 || x > self.width() -1 || y < 0 || y > self.height() - 1 {
            return;
        } 
        self.grid[y][x] = pixel;
    }

    pub fn write_canvas_to_ppm_file(&mut self, filename: &str) {
        let file_data = format!("{}{}", self.create_ppm_header(), self.create_ppm_body());
        let mut file = match File::create(filename) {
            Err(why) => panic!("could not create file, {}", why),
            Ok(file) => file,
        };
        let result = file.write_all(file_data.as_bytes());
        result.err();
    }
    fn create_ppm_header(&self) -> String {
        let header = format!(
            "{}\n{} {}\n{}\n",
            PPM_VERSION,
            self.width(),
            self.height(),
            MAX_COLOR_VALUE
        );
        return header;
    }
    fn create_ppm_body(&self) -> String {
        let mut body: String = String::new();
        let mut cell_count: u32 = 0;
        for row in self.grid.as_slice() {
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
