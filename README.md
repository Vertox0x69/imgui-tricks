# ImTricks

ImTricks is a collection of useful functions for expanding / improving the functionality of the ImGui.

At the moment it has in itself:
* Functions to speed up the creation of animations.
* Functions for creating and displaying notifications.
* Widgets that are missing in the standard ImGui.
* A customized ImColor structure with an additional constructor from the HEX HTML color code and a method for obtaining HEX HTML from an already existing color.

# Notifies Usage

```cpp

void RenderMyGUI() {

   ...
   if (ImGui::Button("Create Notify", { 120, 25 }))
   	ImTricks::NotifyManager::AddNotify("The notification was displayed successfully.", ImTrickNotify_Success);
   ...
   
   ImTricks::NotifyManager::HandleNotifies(ImGui::GetOverlayDrawList());
}

```


# Animations Usage

```cpp

void RenderMyGUI() {
   ...
   ImGui::Checkbox("Enable Animation", &enable_animation);
   float trickFloat = ImTricks::Animations::FastFloatLerp("header", enable_animation, 0.f, 1.f, 0.05f);
   ImVec2 pos1 = ImTricks::Animations::FastImVec2Lerp("pos1", enable_animation, ImVec2(0, 50), ImVec2(100, 50), 5);
   ImVec2 pos2 = ImTricks::Animations::FastImVec2Lerp("pos2", enable_animation, ImVec2(413, 80), ImVec2(513, 80), 5);
   draw->AddRectFilled(p + pos1, p + pos2, ImTricks::Animations::FastColorLerp(ImColor(255, 0, 0), ImColor(0, 255, 0), trickFloat));
   ...
}

```

https://user-images.githubusercontent.com/61081677/130608582-0688ebde-a108-4bc6-b5ed-32dbe9dc05f3.mp4

# Widgets Usage

```cpp

void RenderMyGUI() {
   ...
   static ImColor col = ImColor(23, 23, 23);
   ImTricks::Widgets::ColorEdit4("test", col, NULL);
   ...
}

```

# ImTrickyColor

```cpp

void RenderMyGUI() {
   ...
  	ImTrickyColor color = ImTrickyColor("#eb4034ff");
   ImGui::Text(color.HTML().c_str());
   ...
}

```
