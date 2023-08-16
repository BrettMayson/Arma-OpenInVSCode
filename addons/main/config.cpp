class CfgPatches {
    class open_in_vscode_main {
        name = "open_in_vscode_main";
        units[] = {};
        weapons[] = {};
        requiredVersion = 2.10;
        requiredAddons[] = { "A3_Data_F_AoW_Loadorder" };
        authors[] = {"Brett Mayson"};
        author = "Brett Mayson";
        version = 1.0;
        versionStr = "1.0.0";
        versionAr[] = {1,0,0};
    };
};

class ctrlMenuStrip;
class display3DEN {
    class Controls {
        class MenuStrip: ctrlMenuStrip {
            class Items {
                class File {
                    items[] += {"OpenInVscode"};
                };
                class OpenInVscode {
                    text = "Open in VS Code";
                    action = """open_in_vscode"" callExtension [""open"", [getMissionPath """"]]";
                    picture = "\z\open_in_vscode\addons\main\logo_ca.paa";
                };
            };
        };
    };
};
