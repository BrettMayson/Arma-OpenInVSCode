use std::path::Path;

use arma_rs::{arma, Extension};

#[arma]
fn init() -> Extension {
    Extension::build()
        .version("1.0.0".to_string())
        .command("open", open)
        .finish()
}

fn open(mut mission_path: String) -> bool {
    if mission_path.ends_with('\\') {
        mission_path.pop();
    };
    if mission_path.is_empty() {
        return false;
    }
    let path = Path::new(&mission_path);
    if !path.exists() {
        return false;
    }
    if !path.is_dir() {
        return false;
    }
    std::process::Command::new("code.cmd")
        .arg(path)
        .spawn()
        .is_ok()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_open() {
        assert!(!open("".to_string()));
        assert!(open("src".to_string()));
        assert!(open("src\\".to_string()));
        assert!(!open("src\\lib.rs".to_string()));
    }
}
