extern crate rand;
extern crate byteorder;

use rand::random;
use byteorder::{NativeEndian, ReadBytesExt, WriteBytesExt};
type NE = NativeEndian;

struct Chip {
    i: u16,             // Address register
    pc: u16,            // Program counter
    ram: [u8; 4096],    // 4K RAM
    v: [u8; 16],        // Registers V0-VF
    stack: [u16; 24],   // Call stack
    sp: u8,             // Stack pointer
    dt: u8,             // Delay timer
    st: u8              // Sound timer
}

impl Chip {
    fn r16(&self, addr: u16) -> u16 {
        let mut loc = &self.ram[(addr as usize)..];
        loc.read_u16::<NE>().unwrap()
    }
    fn execute(m: &mut Self, op: u16) {
        let (code, nnn, nn, n, x, y) = (
            (op & 0xF000) >> 12,
            op & 0x0FFF,
            (op & 0x00FF) as u8,
            (op & 0x000F) as u8,
            ((op & 0x0F00) >> 8) as usize,
            ((op & 0x00F0) >> 4) as usize

        ); 
        let (vx, vy) = (m.v[x], m.v[y]);
        match code {
            0x0 => match nn {
                0xE0 => {}, // 0x00E0: disp_clear()
                0xEE => { m.pc = m.stack[m.sp as usize]; m.sp -= 1; }, // 0x00EE: return
                _ => ()
            },
            0x1 => { m.pc = nnn; }, // 0x1NNN: goto NNN
            0x2 => { m.stack[m.sp as usize] = m.pc; m.sp += 1; m.pc = nnn; }, // 0x2NNN: *(0xNNN)()
            0x3 => { if vx == nn { m.pc += 2 }; }, // 0x3XNN: if(VX==NN) goto PC+1
            0x4 => { if vx != nn { m.pc += 2 }; }, // 0x4XNN: if(VX!=NN) goto PC+1
            0x5 => { if vx == vy { m.pc += 2 }; }, // 0x5XY0: if(VX==VY) goto PC+1
            0x6 => { m.v[x] = nn; }, // 0x6XNN: VX = NN
            0x7 => { m.v[x] += nn; }, // 0x7XNN: VX += NN
            0x8 => match n {
                0x0 => { m.v[x] = vy; }, // 0x8XY0: VX = VY
                0x1 => { m.v[x] = vx | vy; }, // 0x8XY1: VX = VX|VY
                0x2 => { m.v[x] = vx & vy; }, // 0x8XY2: VX = VX&VY
                0x3 => { m.v[x] = vx ^ vy; }, // 0x8XY3: VX = VX^VY
                0x4 => { m.v[x] += vy; }, // 0x8XY4: VX += VY
                0x5 => { m.v[x] -= vy; }, // 0x8XY5: VX -= VY
                0x6 => { m.v[x] = vy >> 1; }, // 0x8XY6: VX = VY>>1
                0x7 => { m.v[x] = vx - vy; }, // 0x8XY7: VX = VX-VY
                0xE => { m.v[x] = vy << 1; }, // 0x8XYE: VX = VY<<1
                _ => ()
            },
            0x9 => { if vx != vy { m.pc += 2; } }, // 0x9XY0: if(VX!=VY) goto PC+2
            0xA => { m.i = nnn; }, // 0xANNN: I = NNN
            0xB => { m.pc = m.v[0] as u16 + nnn; }, // 0xBNNN: PC = V0+NNN
            0xC => { m.v[x] = random::<u8>() & nn; }, // 0xCXNN: VX = rand()&NN
            0xD => {}, // 0xDXYN: draw(VX,VY,N)
            0xE => match nn {
                0x9E => {}, // 0xEX9E: if(key()==VX) goto PC+1
                0xA1 => {}, // 0xEXA1: if(key()!=VX) goto PC+1
                _ => ()
            },
            0xF => match nn {
                0x07 => { m.v[x] = m.dt; }, // 0xFX07: VX = get_delay()
                0x0A => {}, // 0xFX0A: VX = get_key()
                0x15 => { m.dt = vx; }, // 0xFX15: delay_timer(VX)
                0x18 => { m.st = vx; }, // 0xFX18: sound_timer(VX)
                0x1E => { m.i += vx as u16; }, // 0xFX1E: I += VX
                0x29 => {}, // 0xFX29: I = sprite_addr[VX]
                0x33 => { // 0xFX33: BCD...
                    let mut bcx = vx;
                    for i in 0..3 {
                        let fact: u8 = 100 / (i * 10);
                        m.ram[(m.i + i as u16) as usize] = bcx / fact;
                        bcx %= fact;
                    }
                },
                0x55 => { // 0xFX55: reg_dump(VX,&I)
                    let dl = &mut m.ram[m.i as usize..=(m.i + x as u16) as usize];
                    let ds = &m.v[0..=x as usize];
                    dl.clone_from_slice(ds);
                },
                0x65 => { // 0xFX65: reg_load(VX,&I)
                    let dl = &mut m.v[0..=x as usize];
                    let ds = &m.ram[m.i as usize..=(m.i + x as u16) as usize];
                    dl.clone_from_slice(ds);
                }, 
                _ => ()
            },
            _ => ()
        }
    }
}

fn main() {}
