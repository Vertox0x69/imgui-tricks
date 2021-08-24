/*
* ImGui Tricks v1.02
* ImTricks is a library that simplifies and increases the functionality of ImGui.
* At the moment, Imtrucks adds functions to speed up the creation of animated menus,
* adds a notification system, and also adds support for ImColor in ColorEdit3/ColorEdit4.
*
* Made with love by pers0na2.
*/

#include <windows.h>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

#include <imgui.h>
#define IMGUI_DEFINE_MATH_OPERATORS
#include <imgui_internal.h>

#ifndef IMGUI_TRICK_ONCE
#define IMGUI_TRICK_ONCE

enum NotifyState : int {
	ImTrickNotify_Success = 0,
	ImTrickNotify_Warning = 1,
	ImTrickNotify_Danger = 2,
	ImTrickNotify_Default = 3
};

namespace ImTricks {

	/*
	// The Animations namespace contains everything you need to easily create animations in your ImGui menus.
	*/
	namespace Animations {

		/*
		// Usage:
		//  int trickInt = ImTricks::Animations::FastLerpInt("trickInt", enable_animation, 0, 255, 15);
		//  draw->AddRectFilled(p, p + ImVec2(30, 30), ImColor(255, 255, 255, trickInt));
		*/
		extern int FastIntLerp(const char* identifier, bool state, int min, int max, int speed);

		/*
		// Usage:
		//  float trickFloat = ImTricks::Animations::FastLerpInt("trickFloat", enable_animation, 0.f, 1.f, 0.05f);
		//  draw->AddRectFilled(p, p + ImVec2(30, 30), ImColor(1.f, 1.f, 1.f, trickFloat));
		*/
		extern float FastFloatLerp(const char* identifier, bool state, float min, float max, float speed);


		/*
		// Usage:
		//  float trickFloat = ImTricks::Animations::FastFloatLerp("header", enable_animation, 0.f, 1.f, 0.05f);
		//  ImVec2 pos1 = ImTricks::Animations::FastImVec2Lerp("pos1", enable_animation, ImVec2(0, 50), ImVec2(100, 50), 5);
		//  ImVec2 pos2 = ImTricks::Animations::FastImVec2Lerp("pos2", enable_animation, ImVec2(413, 80), ImVec2(513, 80), 5);
		//  draw->AddRectFilled(p + pos1, p + pos2, ImTricks::Animations::FastColorLerp(ImColor(255, 0, 0), ImColor(0, 255, 0), trickFloat));
		*/
		extern ImVec2 FastImVec2Lerp(const char* identifier, bool state, ImVec2 min, ImVec2 max, float speed);

		/*
		// Usage:
		//	float trickFloat = ImTricks::Animations::FastLerpFloat("header", check, 0.f, 1.f, 0.05f);
		//	draw->AddRectFilled(p, p + ImVec2(513, 30), ImTricks::Animations::FastColorLerp(ImColor(255, 0, 0), ImColor(0, 255, 0), trickFloat));
		*/
		extern ImColor FastColorLerp(ImColor start, ImColor end, float stage);
	}

	/*
	// The NotifyManager namespace contains everything you need to easily create notifications in your interface.
	*/
	namespace NotifyManager {

		struct NotifyStruct {
			const char* message;
			NotifyState state;
			ULONGLONG time;
		};

		extern std::vector<NotifyStruct> notifies;

		/*
		// Description:
		// Responsible for adding notifications to the display queue.
		//
		//	if (ImGui::Button("Create Notify", { 120, 25 }))
		//		ImTricks::NotifyManager::AddNotify("The notification was displayed successfully.", ImTrickNotify_Success);
		*/
		extern void AddNotify(const char* message, NotifyState state);

		/*
		// Description:
		// Call a function in your render. This function is responsible for displaying and monitoring notifications.
		//
		// Usage:
		// ImTricks::NotifyManager::HandleNotifies(ImGui::GetOverlayDrawList());
		*/
		extern void HandleNotifies(ImDrawList* draw = ImGui::GetOverlayDrawList());

	}


	namespace Widgets {

		// I don't understand why ocornut didn't add ImColor support to ColorEdit.
		extern void ColorEdit3(const char* label, ImColor& color, ImGuiColorEditFlags flags = NULL);
		extern void ColorEdit4(const char* label, ImColor& color, ImGuiColorEditFlags flags = NULL);

	}
}

static inline ImVec2 operator+(const ImVec2& lhs, const float rhs) { return ImVec2(lhs.x + rhs, lhs.y + rhs); }
static inline ImVec2 operator-(const ImVec2& lhs, const float rhs) { return ImVec2(lhs.x - rhs, lhs.y - rhs); }
static inline ImVec4 operator+(const ImVec4& lhs, const float rhs) { return ImVec4(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs, lhs.w + rhs); }
static inline ImVec4 operator-(const ImVec4& lhs, const float rhs) { return ImVec4(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs, lhs.w - rhs); }


#endif