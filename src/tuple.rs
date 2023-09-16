
use std::ops::{ Add, Sub, Mul, Div, Not};

#[cfg(test)]
#[path ="./tests/tuple.rs"] mod tuple;

#[derive(Copy, Clone, PartialEq, Debug)]
pub enum TupleKind {
    Vector,
    Point,
    Color
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

    pub fn color(red: f32, green: f32, blue: f32) -> Tuple {
        return Tuple { x: red, y: green, z: blue, w: TupleKind::Color };
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

    pub fn hadamard_product(a: &Tuple, b: &Tuple) -> Tuple {
        return Tuple {x: a.x * b.x, y: a.y * b.y, z: a.z * b.z, w: a.w}
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
