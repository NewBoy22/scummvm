/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "bladerunner/script/script.h"

namespace BladeRunner {

void ScriptKP05::InitializeScene() {
	if (Game_Flag_Query(577)) {
		Setup_Scene_Information(-868.0f, 0.0f, -68.0f, 520);
	} else if (Game_Flag_Query(574)) {
		Setup_Scene_Information(-1142.0f, 0.0f, 932.0f, 276);
	} else {
		Setup_Scene_Information(-802.0f, 0.0f, 972.0f, 800);
	}
	Scene_Exit_Add_2D_Exit(0, 589, 0, 639, 479, 1);
	Scene_Exit_Add_2D_Exit(1, 0, 0, 30, 479, 3);
	Scene_Exit_Add_2D_Exit(2, 0, 0, 257, 204, 0);
	Ambient_Sounds_Add_Looping_Sound(464, 34, 1, 1);
	Ambient_Sounds_Add_Looping_Sound(383, 27, 1, 1);
	Ambient_Sounds_Add_Looping_Sound(384, 90, 1, 1);
	Ambient_Sounds_Add_Sound(440, 2, 100, 25, 33, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(441, 2, 100, 25, 33, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(442, 2, 100, 25, 33, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(375, 5, 180, 50, 100, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(376, 5, 180, 50, 100, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(377, 5, 180, 50, 100, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(443, 2, 100, 25, 33, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(444, 2, 100, 25, 33, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(445, 2, 100, 25, 33, -100, 100, -101, -101, 0, 0);
}

void ScriptKP05::SceneLoaded() {
	Unobstacle_Object("OBSTACLEBOX20", true);
	Clickable_Object("BRIDGE02");
	Unclickable_Object("BRIDGE02");
	if (!Actor_Clue_Query(0, 145) && Game_Flag_Query(653)) {
		Item_Add_To_World(118, 960, 9, -1095.0f, 0.0f, 770.0f, 256, 24, 24, false, true, false, true);
	}
}

bool ScriptKP05::MouseClick(int x, int y) {
	return false;
}

bool ScriptKP05::ClickedOn3DObject(const char *objectName, bool a2) {
	return false;
}

bool ScriptKP05::ClickedOnActor(int actorId) {
	return false;
}

bool ScriptKP05::ClickedOnItem(int itemId, bool a2) {
	if (itemId == 118) {
		if (!Loop_Actor_Walk_To_XYZ(0, -1058.0f, 0.0f, 852.0f, 0, 1, false, 0)) {
			Actor_Face_Item(0, 118, true);
			Actor_Clue_Acquire(0, 145, 1, -1);
			Item_Remove_From_World(118);
			Item_Pickup_Spin_Effect(960, 58, 321);
		}
	}
	return false;
}

bool ScriptKP05::ClickedOnExit(int exitId) {
	if (exitId == 0) {
		if (!Loop_Actor_Walk_To_XYZ(0, -802.0f, 0.0f, 972.0f, 0, 1, false, 0)) {
			Ambient_Sounds_Remove_All_Non_Looping_Sounds(1);
			Ambient_Sounds_Remove_All_Looping_Sounds(1);
			Game_Flag_Set(420);
			Set_Enter(46, 43);
		}
		return true;
	}
	if (exitId == 1) {
		if (!Loop_Actor_Walk_To_XYZ(0, -1142.0f, 0.0f, 932.0f, 0, 1, false, 0)) {
			Ambient_Sounds_Remove_All_Non_Looping_Sounds(1);
			Ambient_Sounds_Remove_All_Looping_Sounds(1);
			Game_Flag_Set(575);
			Set_Enter(47, 44);
		}
		return true;
	}
	if (exitId == 2) {
		if (!Loop_Actor_Walk_To_XYZ(0, -868.0f, 0.0f, -68.0f, 0, 1, false, 0)) {
			Ambient_Sounds_Remove_All_Non_Looping_Sounds(1);
			Ambient_Sounds_Remove_All_Looping_Sounds(1);
			Game_Flag_Set(576);
			Async_Actor_Walk_To_XYZ(0, -868.0f, 0.0f, -216.0f, 0, false);
			Set_Enter(9, 46);
		}
		return true;
	}
	return false;
}

bool ScriptKP05::ClickedOn2DRegion(int region) {
	return false;
}

void ScriptKP05::SceneFrameAdvanced(int frame) {
}

void ScriptKP05::ActorChangedGoal(int actorId, int newGoal, int oldGoal, bool currentSet) {
}

void ScriptKP05::PlayerWalkedIn() {
	if (Game_Flag_Query(577)) {
		Game_Flag_Reset(577);
	} else if (Game_Flag_Query(574)) {
		Loop_Actor_Walk_To_XYZ(0, -1110.0f, 0.0f, 932.0f, 0, 0, false, 0);
		Game_Flag_Reset(574);
	} else {
		Loop_Actor_Walk_To_XYZ(0, -846.0f, 0.0f, 972.0f, 0, 0, false, 0);
		Game_Flag_Query(419);
	}
	if (Actor_Query_Goal_Number(66) == 411) {
		Actor_Set_Goal_Number(66, 412);
	}
	if (Actor_Query_Goal_Number(1) == 450) {
		Scene_Exits_Disable();
		Actor_Face_Actor(1, 0, true);
		Actor_Says(1, 530, 15);
		Actor_Says(1, 540, 16);
		Actor_Face_Actor(0, 1, true);
		Player_Set_Combat_Mode(true);
		Actor_Says(0, 2200, 3);
		Actor_Says(1, 550, 17);
		Actor_Says(0, 2205, 3);
		Actor_Says(1, 560, 15);
		Actor_Says(1, 570, 16);
		Actor_Says(1, 580, 13);
		Actor_Says(0, 2210, 3);
		Actor_Says(1, 590, 13);
		Actor_Says(0, 2215, 3);
		Actor_Says(1, 600, 16);
		Actor_Says(1, 610, 15);
		Actor_Says(0, 2220, 3);
		Actor_Says(1, 620, 15);
		Actor_Says(1, 630, 17);
		Non_Player_Actor_Combat_Mode_On(1, 0, 1, 0, 9, 4, 7, 8, 0, -1, -1, 20, 240, 0);
	}
}

void ScriptKP05::PlayerWalkedOut() {
}

void ScriptKP05::DialogueQueueFlushed(int a1) {
}

} // End of namespace BladeRunner
