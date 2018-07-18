## gloom
### Install notes: 
    * `QT_HOME`Qt install dir
    * `QT_DLL_DIR` (`QT_HOME/bin`) added to PATH


## Minimum Viable Product
The user can place and edit rooms, tokens and monsters in a scenario - and write an introduction. The composed scenario can be serialized/deserialized between sessions. The scenario can be exported to a format that can be consumed by an average user (image/pdf).

### Room placement
- [x] Browse available rooms
- [ ] Place room in scene
- [ ] Move rooms in scene
- [ ] Rooms can connect via snapping

### Token placement
- [x] Browse available tokens
- [ ] Place tokens in scene
- [ ] Move tokens in scene
- [ ] Snapping placement for tokens

### Monster placement
- [x] Browse available monsters
- [ ] Place monsters in scene
- [ ] Move monsters in scene
- [ ] Snapping placement for monsters
- [ ] Set monster details for player count

### Serialization
- [ ] Save/load scene to json
- [ ] Export to pdf/image