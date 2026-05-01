# 🌌 WestWard

> An Open World Survival RPG set on an alien planet — built with Unreal Engine 5

![UE5](https://img.shields.io/badge/Unreal%20Engine-5.7-blue?logo=unrealengine)
![Platform](https://img.shields.io/badge/Platform-PC%20%7C%20Android-green)
![Language](https://img.shields.io/badge/Language-C%2B%2B%20%7C%20Blueprint-red)
![Status](https://img.shields.io/badge/Status-In%20Development-yellow)

---

## 🎮 About the Game

**WestWard** is a third-person survival RPG where the player crash-lands on an alien planet and must survive against hostile alien enemies while exploring the environment and completing objectives.

Inspired by themes of frontier exploration, alien encounter, and survival instinct — WestWard challenges players to outlast enemies, collect resources, and find a way home.

---

## ✨ Features

- 🤖 **Enemy AI** — Aliens chase and attack the player using UE5 NavMesh pathfinding
- ❤️ **Health System** — Player health bar with real-time damage feedback
- 💀 **Game Over Screen** — Triggered when player health reaches zero, with Restart option
- 🏆 **Win Condition** — Complete the objective to trigger the YOU WIN screen
- 🎯 **Third-Person Controls** — Full movement, camera, and jump support
- 📱 **Mobile Support** — Designed and built for Android (Mobile Game Engines)

---

## 🕹️ How to Play

| Action | Control |
|--------|---------|
| Move | WASD / Left Stick |
| Look | Mouse / Right Stick |
| Jump | Space / A Button |
| Survive | Avoid enemies and complete objectives |

**Objective:** Reach the goal zone before your health runs out!

---

## 🛠️ Tech Stack

| Tool | Usage |
|------|-------|
| Unreal Engine 5.7 | Game Engine |
| Blueprint Visual Scripting | Gameplay Logic |
| C++ | Core Systems |
| NavMesh | AI Pathfinding |
| UMG Widget | HUD / UI |
| Android SDK | Mobile Build |

---

## 📁 Project Structure

```
WestWard/
├── Content/
│   ├── BP_Enemy.uasset          # Enemy AI Blueprint
│   ├── WBP_HUD.uasset           # Health Bar HUD
│   ├── WBP_YouWin.uasset        # Win Screen Widget
│   ├── ThirdPerson/             # Player Character & Level
│   └── Characters/              # Mannequin Meshes & Animations
├── Source/
│   └── WestWard/
│       ├── WestWardCharacter    # Player Character C++
│       ├── WestWardEnemy        # Enemy Base C++
│       └── WestWardGameMode     # Game Mode C++
└── Config/                      # Engine & Game Settings
```

---

## 🚀 Getting Started

### Prerequisites
- Unreal Engine 5.7+
- Visual Studio 2022
- Android SDK (for mobile build)

### Run the Project
1. Clone this repo
2. Right-click `WestWard.uproject` → Generate Visual Studio project files
3. Open `WestWard.uproject` in UE5
4. Press **Play** in the editor

---

## 👨‍💻 Contributors

| Name | Role |
|------|------|
| **Bryan Rozel Bin Leo** | Developer — AI, Gameplay, UI, Level Design |

---

## 📚 Assignment Info

| Field | Details |
|-------|---------|
| Course | CMD3333 — Mobile Game Engines |
| Institution | Universiti Teknologi MARA (UiTM) |
| Deadline | 28 May 2026 |
| Presentation | 11 June 2026 |

---

## 📸 Screenshots

*Coming soon* ( official 4 May 2026 ) 

---

## 📄 License

This project is developed for academic purposes as part of the CMD3333 coursework.

---

*Made with ❤️ using Unreal Engine 5*
