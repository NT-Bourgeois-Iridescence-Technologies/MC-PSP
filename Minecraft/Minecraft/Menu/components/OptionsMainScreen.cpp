#include "../MenuState.hpp"

namespace Minecraft::Menus{
    void MenuState::optionsMainScreenDraw(){
        for(int x = 0; x < 16; x++){
            for(int y = 0; y < 9; y++){
                options_tile->RGB(64.0f, 64.0f, 64.0f);
                options_tile->SetPosition(x * 32, y * 32);
                options_tile->Draw();
            }

            opt_dis->SetPosition(152, 48);
            opt_dis->Draw();

            slider->SetPosition(152 + (Common::g_OptionsManager.options.fov * 40)*2, 48);
            slider_sel->SetPosition(152 + (Common::g_OptionsManager.options.fov * 40)*2, 48);
            slider->Draw();
            if(selectRegion == 0 && selectPosY == 0){
                slider_sel->Draw();
            }


            opt_unsel->SetPosition(168 + 160, 48);
            opt_unsel->Draw();

            if(selectRegion == 1 && selectPosY == 0){
                opt_sel->SetPosition(168 + 160, 48);
                opt_sel->Draw();
            }

            //Main render region

            for(int i = 0; i < 4; i++){
                opt_unsel->SetPosition(168 + 160, 108 + i * 24);
                opt_unsel->Draw();
            }

            for(int i = 0; i < 4; i++){
                opt_unsel->SetPosition(152, 108 + i * 24);
                opt_unsel->Draw();
            }

            //Selected Main Region.

            if(selectPosY > 0 && selectPosY < 5){
                opt_sel->SetPosition(152 + 176 * selectRegion, 108 + (selectPosY-1) * 24);
                opt_sel->Draw();
            }

            unselected->SetPosition(240, 272 - 24);
            unselected->Draw();

            if(selectPosY == 5){
                selected->SetPosition(240, 272 - 24);
                selected->Draw();
            }

                        
        }

        g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderManager.DebugPrint(240, 32, Common::g_TranslationOBJ.getText("options.title").c_str());
        
        if(selectRegion == 0 && selectPosY == 0){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(152, 48, "%s: %.1f", Common::g_TranslationOBJ.getText("options.fov").c_str(), Common::g_OptionsManager.options.fov * 40 + 70);
        
        if(selectRegion == 1 && selectPosY == 0){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(168  + 160, 48, "%s: %s", Common::g_TranslationOBJ.getText("options.realmsNotifications").c_str(), (Common::g_OptionsManager.options.realmsNotifications) ? Common::g_TranslationOBJ.getText("options.on").c_str() : Common::g_TranslationOBJ.getText("options.off").c_str());

        if(selectRegion == 0 && selectPosY == 1){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(152, 108, Common::g_TranslationOBJ.getText("options.skinCustomisation").c_str());
        
        if(selectRegion == 0 && selectPosY == 2){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(152, 108 + 24, Common::g_TranslationOBJ.getText("options.video").c_str());
        
        if(selectRegion == 0 && selectPosY == 3){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(152, 108 + 48, Common::g_TranslationOBJ.getText("options.language").c_str());
        
        if(selectRegion == 0 && selectPosY == 4){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(152, 108 + 72, Common::g_TranslationOBJ.getText("options.resourcepack").c_str());

        if(selectRegion == 1 && selectPosY == 1){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(168 + 160, 108, Common::g_TranslationOBJ.getText("options.sounds").c_str());
        
        if(selectRegion == 1 && selectPosY == 2){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(168 + 160, 108 + 24, Common::g_TranslationOBJ.getText("options.controls").c_str());
        
        if(selectRegion == 1 && selectPosY == 3){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(168 + 160, 108 + 48, Common::g_TranslationOBJ.getText("options.chat.title").c_str());
        
        if(selectRegion == 1 && selectPosY == 4){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(168 + 160, 108 + 72, Common::g_TranslationOBJ.getText("options.accessibility.title").c_str());

        if(selectPosY == 5){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(240, 272 - 24, Common::g_TranslationOBJ.getText("gui.done").c_str());
    }
	void MenuState::optionsMainScreenUpdate(){
        if(g_System.KeyPressed(PSP_CTRL_RTRIGGER)){
            g_AudioManager.PlaySound(button, AUDIO_CHANNEL_GUI);
            selectRegion++;
            if(selectRegion > 1){
                selectRegion = 1;
            }
        }

        if(g_System.KeyPressed(PSP_CTRL_LTRIGGER)){
            g_AudioManager.PlaySound(button, AUDIO_CHANNEL_GUI);
            selectRegion--;
            if(selectRegion < 0){
                selectRegion = 0;
            }
        }

        if(g_System.KeyPressed(PSP_CTRL_DOWN)){
            g_AudioManager.PlaySound(button, AUDIO_CHANNEL_GUI);
            selectPosY++;
            if(selectPosY > 5){
                selectPosY = 5;
            }
        }
        
        if(g_System.KeyPressed(PSP_CTRL_UP)){
            g_AudioManager.PlaySound(button, AUDIO_CHANNEL_GUI);
            selectPosY--;
            if(selectPosY < 0){
                selectPosY = 0;
            }
        }

        if(g_System.KeyPressed(PSP_CTRL_LEFT)){
            if(selectPosY == 0 && selectRegion == 0){
                Common::g_OptionsManager.options.fov -= 1 / 40.0f;
            }
            if(Common::g_OptionsManager.options.fov < -1){
                Common::g_OptionsManager.options.fov = -1.0f;
            }
        }
        if(g_System.KeyPressed(PSP_CTRL_RIGHT)){
            if(selectPosY == 0 && selectRegion == 0){
                Common::g_OptionsManager.options.fov += 1 / 40.0f;
            }
            if(Common::g_OptionsManager.options.fov > 1){
                Common::g_OptionsManager.options.fov = 1.0f;
            }
        }
    

        if(g_System.KeyPressed(PSP_CTRL_CROSS)){
            g_AudioManager.PlaySound(button, AUDIO_CHANNEL_GUI);
            if(selectRegion == 0){ //LEFT SIDE
                if(selectPosY == 0){} //NOTHING, this is modified by L/R
                if(selectPosY == 1){
                    //SKIN CUSTOMIZATION
                }
                if(selectPosY == 2){
                    //VIDEO SETTINGS!
                }
                if(selectPosY == 3){
                    //LANGUAGE!
                    selectPosX = 0;
                    selectPosY = 0;
                    selectRegion = 0;
                    previous_states = menu_states;
                    menu_states = MENU_STATE_LANGUAGE;
                }
                if(selectPosY == 4){
                    //RESOURCE PACKS
                    //TODO: ASK DARTH!
                }
            }
            if(selectRegion == 1){ //RIGHT SIDE
                if(selectPosY == 0){
                    //REALMS NOTIFICATIONS
                    Common::g_OptionsManager.options.realmsNotifications = !Common::g_OptionsManager.options.realmsNotifications;
                } 
                if(selectPosY == 1){
                    //MUSIC & SOUNDS
                    
                }
                if(selectPosY == 2){
                    //CONTROLS
                }
                if(selectPosY == 3){
                    //CHAT SETTINGS
                }
                if(selectPosY == 4){
                    //ACCESSIBILITY SETTINGS
                }
            }
            if(selectPosY == 5){
                selectPosX = 0;
                selectPosY = 0;
                selectRegion = 0;
                menu_states = MENU_STATE_TITLE;
                previous_states = MENU_STATE_OPTIONS_MAIN;

                //CLOSE OPTIONS STREAMING!
                Common::g_OptionsManager.close();
            }
        }
    }
}