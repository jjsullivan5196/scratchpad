fn bin_search(n: i32, arr: &[i32]) -> Option<i32> {
    if n < arr[0] || n > *arr.last()? { return None; }
    let mut left: usize = 0; let mut right: usize = arr.len() - 1;
    let mut mid: usize = (left + right)/2;

    while left < right {
        if arr[mid] == n { return Some(mid as i32); }
        if n > arr[mid] { left = mid + 1 } else { right = mid - 1 };
        mid = (left + right)/2;
    }
    
    if arr[mid] == n { Some(mid as i32) } else { None }
}

fn main() {
    let arr = [2, 5, 10, 17, 22, 36];
    for i in 0..14 {
        println!("{:?}", bin_search(i, &arr[..]));
    }
}
