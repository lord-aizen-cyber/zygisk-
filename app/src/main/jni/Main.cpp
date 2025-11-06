#include <android/log.h>
#include <unistd.h>
#include <thread>
#include <limits>
#include <xdl.h>
#include <KittyUtils.h>
#include <KittyMemory.h>
#include <Il2Cpp.h>
#include <SubstrateHook.h>
#include <CydiaSubstrate.h>
#include "KittyMemory/MemoryPatch.h"
#include "Struct/Gui.hpp"
#include <Struct/main.h>
#include "fonts/FontAwesome6_solid.h"
#include "ImGui/Toggle.h"
#include "zygisk.hpp"
#include "Aizen-Chams.h"



 
using zygisk::Api;
using zygisk::AppSpecializeArgs;
using zygisk::ServerSpecializeArgs;

void hack();

class MyModule : public zygisk::ModuleBase {
 public:
  void onLoad(Api *api, JNIEnv *env) override {
    this->api_ = api;
    this->env_ = env;
    genv = env;
  }
  void preAppSpecialize(AppSpecializeArgs *args) override {
    static constexpr const char *packages[] = {
      "com.dts.freefireth"  
    }; // Game Package Names
    const char *process = env_->GetStringUTFChars(args->nice_name, nullptr);
    for (const auto *package: packages) {
      is_game_ = (strcmp(process, package) == 0);
      if (is_game_) {
        break;
      }
    }
    env_->ReleaseStringUTFChars(args->nice_name, process);
  }
  void postAppSpecialize(const AppSpecializeArgs *args) override {
    if (is_game_) {
       genv->GetJavaVM(&jvm);
      std::thread{hack}.detach();
    }
  }
 private:
  Api *api_ = nullptr;
  JNIEnv *env_ = nullptr;
  bool is_game_ = false;
};
void SetElegantBlackAndRedTheme(){
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGuiStyle* style = &ImGui::GetStyle();
    style->Alpha = 1.0f;
    style->WindowRounding = 10.0f;
    style->WindowTitleAlign = ImVec2(0.5f, 0.5f);
    style->FrameRounding = 10.0f;
    style->FramePadding = ImVec2(4, 7);
    style->ScrollbarSize = 25;
    style->Colors[ImGuiCol_Text]                 = ImColor(255, 255, 255, 255);
    style->Colors[ImGuiCol_TextDisabled]         = ImColor(130, 130, 130, 255);
    style->Colors[ImGuiCol_WindowBg]             = ImColor(15, 15, 20, 255);
    style->Colors[ImGuiCol_ChildBg]              = ImColor(20, 20, 25, 220);
    style->Colors[ImGuiCol_PopupBg]              = ImColor(25, 25, 30, 240);
    style->Colors[ImGuiCol_Border]               = ImColor(120, 0, 0, 180);
    style->Colors[ImGuiCol_BorderShadow]         = ImVec4(0, 0, 0, 0);
    style->Colors[ImGuiCol_FrameBg]              = ImColor(100, 0, 0, 180);
    style->Colors[ImGuiCol_FrameBgHovered]       = ImColor(180, 30, 30, 220);
    style->Colors[ImGuiCol_FrameBgActive]        = ImColor(255, 60, 60, 255);
    style->Colors[ImGuiCol_TitleBg]              = ImColor(60, 0, 0, 255);
    style->Colors[ImGuiCol_TitleBgActive]        = ImColor(180, 0, 0, 255);
    style->Colors[ImGuiCol_TitleBgCollapsed]     = ImColor(50, 0, 0, 130);
    style->Colors[ImGuiCol_MenuBarBg]            = ImColor(40, 0, 0, 255);
    style->Colors[ImGuiCol_ScrollbarBg]          = ImColor(15, 10, 10, 160);
    style->Colors[ImGuiCol_ScrollbarGrab]        = ImColor(180, 40, 40, 255);
    style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImColor(220, 60, 60, 255);
    style->Colors[ImGuiCol_ScrollbarGrabActive]  = ImColor(255, 80, 80, 255);
    style->Colors[ImGuiCol_Separator]            = ImColor(255, 255, 255, 160);
    style->Colors[ImGuiCol_SeparatorHovered]     = ImColor(255, 255, 255, 200);
    style->Colors[ImGuiCol_SeparatorActive]      = ImColor(255, 255, 255, 255);
    style->Colors[ImGuiCol_CheckMark]            = ImColor(255, 60, 60, 255);
    style->Colors[ImGuiCol_SliderGrab]           = ImColor(200, 50, 50, 255);
    style->Colors[ImGuiCol_SliderGrabActive]     = ImColor(255, 80, 80, 255);
    style->Colors[ImGuiCol_Button]               = ImColor(160, 20, 20, 200);
    style->Colors[ImGuiCol_ButtonHovered]        = ImColor(200, 40, 40, 255);
    style->Colors[ImGuiCol_ButtonActive]         = ImColor(255, 60, 60, 255);
    style->Colors[ImGuiCol_Header]               = ImColor(180, 30, 30, 180);
    style->Colors[ImGuiCol_HeaderHovered]        = ImColor(220, 50, 50, 220);
    style->Colors[ImGuiCol_HeaderActive]         = ImColor(255, 70, 70, 255);
    style->Colors[ImGuiCol_ResizeGrip]           = ImColor(200, 40, 40, 160);
    style->Colors[ImGuiCol_ResizeGripHovered]    = ImColor(230, 60, 60, 255);
    style->Colors[ImGuiCol_ResizeGripActive]     = ImColor(255, 80, 80, 255);
    style->Colors[ImGuiCol_Tab]                  = ImColor(120, 20, 20, 220);
    style->Colors[ImGuiCol_TabHovered]           = ImColor(200, 40, 40, 255);
    style->Colors[ImGuiCol_TabActive]            = ImColor(255, 60, 60, 255);
    style->Colors[ImGuiCol_TabUnfocused]         = ImColor(60, 10, 10, 150);
    style->Colors[ImGuiCol_TabUnfocusedActive]   = ImColor(100, 20, 20, 200);
    style->Colors[ImGuiCol_PlotLines]            = ImVec4(1.0f, 0.5f, 0.5f, 1.0f);
    style->Colors[ImGuiCol_PlotLinesHovered]     = ImVec4(1.0f, 0.3f, 0.3f, 1.0f);
    style->Colors[ImGuiCol_PlotHistogram]        = ImVec4(1.0f, 0.4f, 0.4f, 1.0f);
    style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.0f, 0.2f, 0.2f, 1.0f);
    style->Colors[ImGuiCol_TableHeaderBg]        = ImColor(60, 0, 0, 255);
    style->Colors[ImGuiCol_TableBorderStrong]    = ImColor(100, 0, 0, 255);
    style->Colors[ImGuiCol_TableBorderLight]     = ImColor(70, 0, 0, 255);
    style->Colors[ImGuiCol_TableRowBg]           = ImColor(0, 0, 0, 0);
    style->Colors[ImGuiCol_TableRowBgAlt]        = ImColor(255, 255, 255, 10);
    style->Colors[ImGuiCol_TextSelectedBg]       = ImColor(255, 60, 60, 100);
    style->Colors[ImGuiCol_DragDropTarget]       = ImColor(255, 100, 100, 230);
    style->Colors[ImGuiCol_NavHighlight]         = ImColor(255, 60, 60, 255);
    style->Colors[ImGuiCol_NavWindowingHighlight]= ImColor(255, 255, 255, 180);
    style->Colors[ImGuiCol_NavWindowingDimBg]    = ImColor(150, 0, 0, 60);
    style->Colors[ImGuiCol_ModalWindowDimBg]     = ImColor(150, 0, 0, 90);}


void(*Bypass1)(void* _this);
void _Bypass1(void* _this) {
    return;
}
void(*Bypass2)(void* _this);
void _Bypass2(void* _this) {
    return;
}
void (*BYPAS)() = 0;
void _BYPAS(void* unk) {
    return;
}





uintptr_t il2cpp_base = 0;
void *getRealAddr(ulong offset) {
    return reinterpret_cast<void*>(il2cpp_base + offset);
};

namespace Settings
{
    static int Tab = 1;
}




bool clearMousePos = true;
bool initImGui = false;

inline EGLBoolean (*old_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
inline EGLBoolean hook_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    eglQuerySurface(dpy, surface, EGL_WIDTH, &g_GlWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &g_GlHeight);

    if (!g_IsSetup) {
        prevWidth = g_GlWidth;
        prevHeight = g_GlHeight;
        SetupImgui();
        
        g_IsSetup = true;
    }

    ImGuiIO &io = ImGui::GetIO();
    SetElegantBlackAndRedTheme();
    
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(g_GlWidth, g_GlHeight);
    ImGui::NewFrame();
    int touchCount = (((int (*)())(Class_Input__get_touchCount))());
    if (touchCount > 0) {
        UnityEngine_Touch_Fields touch = ((UnityEngine_Touch_Fields(*)(int))(Class_Input__GetTouch))(0);
        float reverseY = io.DisplaySize.y - touch.m_Position.fields.y;
        switch (touch.m_Phase) {
            case TouchPhase::Began:
            case TouchPhase::Stationary:
                io.MousePos = ImVec2(touch.m_Position.fields.x, reverseY);
                io.MouseDown[0] = true;
                break;
            case TouchPhase::Ended:
            case TouchPhase::Canceled:
                io.MouseDown[0] = false;
                clearMousePos = true;
                break;
            case TouchPhase::Moved:
                io.MousePos = ImVec2(touch.m_Position.fields.x, reverseY);
                break;
            default:
                break;
        }
    }
	
    DrawESP(g_GlWidth, g_GlHeight);
       ImGui::SetNextWindowSize(ImVec2((float) g_GlWidth * 0.34f, (float) g_GlHeight * 0.54f), ImGuiCond_Once);
             if (false && ImGui::Begin(ICON_FA_GAMEPAD"  IG: AIZENFOURONE", 0, ImGuiWindowFlags_NoBringToFrontOnFocus)) {
	           /* if (ImGui::Begin((ICON_FA_GAMEPAD"  IG: AIZENFOURONE"), nullptr,
ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_AlwaysAutoResize)) {*/
        if (ImGui::BeginTabBar("Tab", ImGuiTabBarFlags_FittingPolicyScroll)) {
			if (ImGui::BeginTabItem(OBFUSCATE(ICON_FA_CROSSHAIRS "  AIM FIRE"))) {
             ImGui::Checkbox(OBFUSCATE("AIMBOT"), &Aimbot);   
			 
          //   ImGui::Text("AIMBOT SETTINGS");
             ImGui::Combo("##AimDir",&AimWhen,dir,IM_ARRAYSIZE(dir));
             if(AimWhen == 0) {
             }
             else if(AimWhen == 1){
             }
             else if(AimWhen == 2) {
             }
             ImGui::SliderFloat(OBFUSCATE("FOV"),&Fov_Aim,0.0f,500.0f,"%.f");  
             ImGui::SliderFloat(OBFUSCATE("DISTANCE"),&Aimdis,0.0f,1000.0f,"%.f");
                ImGui::EndTabItem();
            }
            	if (ImGui::BeginTabItem(OBFUSCATE(ICON_FA_EYE"  VISUAL"))) {
              	ImGui::Checkbox("ENABLE FUNCTION", &Enable);
                ImGui::Checkbox("ESP LINE", &Config.ESP.Line);
                ImGui::Checkbox("ESP BOX", &Config.ESP.Box);
                ImGui::Checkbox("ESP HEALTH", &Config.ESP.Health);
                ImGui::Checkbox("ESP INFO", &Config.ESP.RamaMods);
                ImGui::EndTabItem();
				}
				if(ImGui::BeginTabItem(OBFUSCATE(ICON_FA_PALETTE" CHAMS"))){
				ImGui::Checkbox(OBFUSCATE("Default Chams"), &chams);  //chams   
                ImGui::Checkbox(OBFUSCATE("Shading Chams"), &shading);     
                ImGui::Checkbox(OBFUSCATE("Wireframe Chams"), &wireframe);
                ImGui::Checkbox(OBFUSCATE("Glow Chams"), &glow);     
                ImGui::Checkbox(OBFUSCATE("Outline Chams"), &outline);  
                ImGui::Checkbox(OBFUSCATE("rainbow Chams"), &rainbow);
			    ImGui::EndTabItem();
            }
			if (ImGui::BeginTabItem(OBFUSCATE(ICON_FA_SAVE"  MEMORY"))) {
		    //	ImGui::Checkbox("AIM SILENT", &SilentAim);
			    ImGui::Checkbox(OBFUSCATE("CAMERA HACK"), &camxa);   
	     		ImGui::Checkbox("RESET GUEST", &Guest);		
	
                ImGui::EndTabItem();
            }
         	if (ImGui::BeginTabItem(OBFUSCATE(ICON_FA_COGS"  SETTING"))) {
                ImGui::Text("</> DEV: AIZEN");
                ImGui::Text(ICON_FA_TELEGRAM"  TG OWNER: @AIZEN");
                ImGui::Text(ICON_FA_TELEGRAM"  TG CHANNEL: @AIZEN");
                ImGui::Separator();
                ImGui::Text("ZYGISK  AIZEN");
                ImGui::EndTabItem();
            }
			ImGui::EndTabBar();
        }
    }
      ImGui::EndChild();
    ImGui::End();
    ImGui::Render();
    
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        return old_eglSwapBuffers(dpy, surface);
}


typedef unsigned long DWORD;
 static uintptr_t libBase;



inline void StartGUI() {
    void *ptr_eglSwapBuffer = DobbySymbolResolver("/system/lib/libEGL.so", "eglSwapBuffers");
    if (ptr_eglSwapBuffer != nullptr) {
        DobbyHook((void *)ptr_eglSwapBuffer, (void *)hook_eglSwapBuffers, (void **)&old_eglSwapBuffers);
        LOGD("GUI started successfully");
    }
}






void hack_thread(pid_t pid) {
    LOGD("Hack Thread initiated for PID: %i", pid);

    for (int i = 0; i < 10; i++) {
        il2cpp_base = get_module_base(pid, "libil2cpp.so");
        if (il2cpp_base != 0) break;
        sleep(10);
    }

    if (il2cpp_base == 0) {
        LOGE("libil2cpp.so not found in thread %d", pid);
        std::terminate();
    }

    LOGD("IL2CPP base address: 0x%" PRIxPTR, il2cpp_base);
    sleep(10);

	

	
    Il2CppAttach();
	
//offset camera hack auto update
DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("FollowCamera"), OBFUSCATE("get_OffsetForNormal"), 0),(void *)_GetCameraHeightRateValue, (void **)&GetCameraHeightRateValue);
//offset resetguest auto update 
DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW"), OBFUSCATE("GameConfig"), OBFUSCATE("get_ResetGuest"), 0), (void *)_ResetGuest, (void **)&ResetGuest);  
//chams
if (Aizen()) {
    setShader("_AlphaMask");
    LogShaders();
    Wallhack();
	 }
//chams selesai
	 
	 
    StartGUI();
	
}



    
void hack() {
     LOGD("Inject Ok");
    std::thread thread_hack(hack_thread, getpid());
    thread_hack.detach();
    
}

REGISTER_ZYGISK_MODULE(MyModule)

