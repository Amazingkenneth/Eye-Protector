#include "Eye-Protector.h"
using namespace std;
using namespace WinToastLib;
WinToastTemplate templ;
class CustomHandler : public IWinToastHandler {
public:
  void toastActivated() const { }

  void toastActivated(int actionIndex) const { }

  void toastDismissed(WinToastDismissalReason state) const { }

  void toastFailed() const { }
};
void SetTheme() {
  DWORD color = 0;
  BOOL opaque = FALSE;
  HRESULT hr = DwmGetColorizationColor(&color, &opaque);
  if (SUCCEEDED(hr) && (color >> 16) % 256 + (color >> 8) % 256 + color % 256 > 256) {
    templ.setImagePath(L"%USERPROFILE%\\Pictures\\Saved\ Pictures\\img-light.png");
  } else {
    templ.setImagePath(L"%USERPROFILE%\\Pictures\\Saved\ Pictures\\img-dark.png");
  }
}
int main() {
  if (!WinToast::isCompatible()) {
    wcout << L"Error, your system do not support!" << endl;
  }
  //ShowWindow(GetForegroundWindow(), SW_MINIMIZE); 似乎总有问题
  WinToast::instance()->setAppName(L"Eye-Protector");
  const auto aumi = WinToast::configureAUMI(L"Yankang", L"Eye-Protector", L"Eye-Protector", L"v1.3");
  WinToast::instance()->setAppUserModelId(aumi);
  if (!WinToast::instance()->initialize()) {
    wcout << L"Error: could not initialize the lib!" << endl;
  }
  templ = WinToastTemplate(WinToastTemplate::ImageAndText02);
  //templ.setAudioPath(L"assets/song.m4a");
  templ.setTextField(L"是时候保护下眼睛了", WinToastTemplate::FirstLine);
  templ.setExpiration(25000);
  wcout << "科学用眼，避免疲劳" << endl;
  SetTheme();
  for (int i = 1; true; ++i) {
    Sleep((20 * 60 - 30) * CLOCKS_PER_SEC); // It has seconds delay (here is for 30 seconds).
    templ.setTextField((L"您已经用眼 " + to_wstring(i * 20) + L" 分钟了~").c_str(), WinToastTemplate::SecondLine);
    WinToast::instance()->showToast(templ, new CustomHandler());
    time_t a = clock();
    while (clock() - a < 25 * CLOCKS_PER_SEC);
    wcout << "Have done " << i << " row" << (i > 1 ? "s" : "") << ", which means you have use the computer for " << i * 20 << " minutes." << endl;
  }
  return 0;
}