# COMP-3400 Final Project - Team 7

| Name          |         Contribution          |
| ------------- | ----------------------------- |
| Hadiyah Arif  | Pharmacy & Nurse Code         |
| Josiah Henson | Hospital Code & SQL Database  |
| Faria Islam   | Doctor & Patient Code         |

## Build & Run

To run in codespace:
```
g++ src/mainmenu.cpp src/modules/*.cpp SQLiteCpp/src/*.cpp -o hospitalSystem -I SQLiteCpp/include -I src/include -lsqlite3
```

If that doesnt work, try:
```
g++ src/mainmenu.cpp src/modules/*.cpp SQLiteCpp/src/*.cpp -o hospitalSystem -I SQLiteCpp/include -I src/include -lsqlite3
```

Then :
```
./hospitalSystem
```

### Debian (WSL)
Note: The paths to the SQL files may be incorrect when running locally (to support running in Codespaces). Change the paths in `database.cpp` from `/sql` to `../sql`.
#### Requirements
- gcc v12.x
- Cmake
#### Build
In the root folder, run `build.sh`
#### Run
In `/build`, run `hms`. The database SQLite file will be create in `/build` as `hms.db3`.

## Presentation Slides:
https://www.canva.com/design/DAGjCmUITMA/quZPshsPzRhmDX8a_TUUfg/edit?utm_content=DAGjCmUITMA&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton
