# How to SETUP the mod
1) dayz tools => `mount p drive`
2) dayz tools => `extract game data`
3) `civilwar95\civilwar95\workbench\` config the `user.cfg` (create it)
4) `civilwar95\civilwar95\workbench\batchfiles\` execute `SetupMod.bat`

# How to UPDATE the mod
1) `civilwar95\civilwar95\workbench\batchfiles\` execute `CI.bat`
2) `P:\Mods\` copy `@civilwar95` and paste it inside steamcmd install folder
3) open `steam cmd` and enter the following commands
```
login <username> <password>
workshop_build_item @CivilWar95.vdf
```