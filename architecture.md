# Внутренности

#### enum Symbol 
- emply / cross / zero / ...

#### Point
- x, y

#### Figure
- vector<\Point>
- rotated(Point = (0, 0)) : Figure // на 90 градусов против часовой (относительно точки)
- shifted(Point, int ind) : Figure // на позиции ind теперь стоит x, y. Остальные сдвинуть соответственно

#### Board
- конечное множество клеток, в которых лежит какой-то Symbol, пустые клетки - те, в которые можно что-то поставить.
- vector\<std::pair\<Point, Symbol>>

### abstract Field
- vector\<Figure> - выигрышные
- get_board() : Board
- get_figures() : vector\<Figure>
- set_cell(int x, int y, Symbol) : bool (сделан ли ход)
- // позиция передается в относительных координатах от последнего get_board

## abstract Player
- get_move(const Field\*, Symbol) : Point



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
- start()
- break()

