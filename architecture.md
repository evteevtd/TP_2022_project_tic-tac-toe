# Внутренности

#### enum Sumbol 
- emply / cross / zero / ...

#### Point
- x, y

#### Figure
- vector<\Point>
- rotated(Point = (0, 0)) : Figure // на 90 градусов против часовой (относительно точки)
- shifted(Point, int ind) : Figure // на позиции ind теперь стоит x, y. Остальные сдвинуть соответственно

### abstract Field
- vector\<Figure> - выигрышные
- get_board() : vector\<vector\<Sumbol>>
- get_figures() : vector\<Figure>
- set_cell(int x, int y, Sumbol) : bool (выиграл ли игрок?)
- // позиция передается в относительных координатах от последнего get_board

## abstract Player
- get_move(const Field\*, Sumbol) : Point



# Взаимодействие

### abstract GameState
- ХодЧеловека - Player\*
- ХодРобота - Player\*
- ОсновноеМеню ...
- ...

## Game
- field : Field\*
- players : vector\<Plauer\*> 
- GameState\*
- Возможно вспомогательные объекты для выполнения:
	- process_events();
	- updete_state();
	- draw();
- именно этот класс "отвечает" за отрисовку (то есть отдает команду, что рисовать)
- возможно большую часть взаимодействия реализуют в себе GameState-ы, а не сама Game
