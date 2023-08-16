let dll = "open_in_vscode_x64.dll";
let src = HEMTT_RFS.join(dll);
let dst = HEMTT_OUT.join(dll);
if !src.copy(dst) {
    fatal("Failed to move " + src + " to " + dst);
}
