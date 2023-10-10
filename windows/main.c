#include <windows.h>

#define ID_CHECKBOX_SYNTAX 101
#define ID_CHECKBOX_PACK   102
#define ID_CHECKBOX_MEDIA  103
#define ID_COMBO_FORMAT    104
#define ID_BUTTON_CONVERT  105
#define ID_EDIT_INPUT      106
#define ID_EDIT_OUTPUT     107
#define ID_BUTTON_BROWSE_INPUT 108
#define ID_BUTTON_BROWSE_OUTPUT 109

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE:
            // Create checkboxes
            CreateWindow("BUTTON", "Only check syntax", WS_CHILD | WS_VISIBLE | BS_CHECKBOX, 10, 10, 200, 20, hwnd, (HMENU)ID_CHECKBOX_SYNTAX, NULL, NULL);
            CreateWindow("BUTTON", "One file", WS_CHILD | WS_VISIBLE | BS_CHECKBOX, 10, 40, 200, 20, hwnd, (HMENU)ID_CHECKBOX_PACK, NULL, NULL);
            CreateWindow("BUTTON", "extern media", WS_CHILD | WS_VISIBLE | BS_CHECKBOX, 10, 70, 200, 20, hwnd, (HMENU)ID_CHECKBOX_MEDIA, NULL, NULL);

            // Create combobox
            CreateWindow("COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, 10, 100, 150, 300, hwnd, (HMENU)ID_COMBO_FORMAT, NULL, NULL);
            SendMessage(GetDlgItem(hwnd, ID_COMBO_FORMAT), CB_ADDSTRING, 0, (LPARAM)"pdf");
            SendMessage(GetDlgItem(hwnd, ID_COMBO_FORMAT), CB_ADDSTRING, 0, (LPARAM)"html");
            SendMessage(GetDlgItem(hwnd, ID_COMBO_FORMAT), CB_ADDSTRING, 0, (LPARAM)"odf");

            // Create edit controls
            CreateWindow("EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 10, 130, 300, 20, hwnd, (HMENU)ID_EDIT_INPUT, NULL, NULL);
            CreateWindow("EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 10, 160, 300, 20, hwnd, (HMENU)ID_EDIT_OUTPUT, NULL, NULL);

            // Create browse buttons
            CreateWindow("BUTTON", "explore 1", WS_CHILD | WS_VISIBLE, 320, 130, 60, 20, hwnd, (HMENU)ID_BUTTON_BROWSE_INPUT, NULL, NULL);
            CreateWindow("BUTTON", "explore 2", WS_CHILD | WS_VISIBLE, 320, 160, 60, 20, hwnd, (HMENU)ID_BUTTON_BROWSE_OUTPUT, NULL, NULL);

            // Create convert button
            CreateWindow("BUTTON", "Convert", WS_CHILD | WS_VISIBLE, 10, 190, 100, 30, hwnd, (HMENU)ID_BUTTON_CONVERT, NULL, NULL);

            break;
        
        case WM_COMMAND:
            if (LOWORD(wParam) == ID_BUTTON_CONVERT) {
                // Обработка нажатия кнопки "Конвертировать"
                // Здесь можно вызвать функции для выполнения конвертации
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "ConverterWindowClass";
    RegisterClass(&wc);

    HWND hwnd = CreateWindow("ConverterWindowClass", "doc convert", WS_OVERLAPPEDWINDOW, 100, 100, 400, 300, NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}
