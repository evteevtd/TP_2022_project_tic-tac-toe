# Механика Игры

#### enum Symbol 
- Emply / Cross / Zero / NoCell ... 

#### Point
- x, y

#### Figure
- vector<\Point>
- rotated(Point = (0, 0)) : Figure // на 90 градусов против часовой (относительно точки)
- shifted(Point, int ind) : Figure // на позиции ind теперь стоит x, y. Остальные сдвинуть соответственно

## abstract IBoard
- реализует конечное множество клеток, в которых лежит какой-то Symbol, пустые клетки - те, в которые можно что-то поставить.
- различные варианты IBoard нужны для различных IField. 

- at() : Symbol
- setCell(Point, Symbol) : bool - произошел ли ход
- getCells() : vector\<Point>

#### RectangeBoard : IBoard
- позволяет хранить только прямоугольные поля

#### MapBoard : IBoard
- позволяет хранить произвольное множество клеток, но работает медленне

## abstract IField
- vector\<Figure> - выигрышные
- getBoard() : const IBoard*
- getFigures() : vector\<Figure>
- setCell(int x, int y, Symbol) : bool (сделан ли ход)

#### RectangleField : IField
- реализует прямоугольное поле произвольного размера.

- board_ : RectangleBoard;

## abstract IPlayer
- get_move(const Field\*, Symbol) : Point

#### RandomAIPlayer : IPlayer
- совершает случайные ходы. Нужен для MVP.

#### HymanPlayer : IPlayer
- узнает ходы у пользователя через inputer_

- inputer_ : IGraphics::Inputer\*;

# Ход Игры

## Game
- Этот класс отвечает за последовательность отрисовки, ходы игроков и определение победителя

- field_ : IField\*
- players_ : vector\<IPlayer\*> 
- graphics_ : IGraphics\*
- run() : IPlayer\*

# Взаимодействие с игроком

## abstract IGraphics
- отвечает за отрисовку игрового поля
- startGame()
- drawField()
- playerWin()
- messageError()
##### class Inputer - внутренний класс IGraphics
    - getMove() : Point
- getInputer() : Inputer*

### ConsoleGraphics : IGraphics
- рисует игровое поле в консоли
##### class Inputer : IGraphics::Inputer
    - принимает данные от пользователя через консоль.

## abstract ILauncher
- отвечает за взаимодействие с пользователем при старте игры, запускает саму Игру
- lounch()
- game_ : Game;

#### ConsoleLauncher
- при запуске игры взаимодействует с пользователем через консоль.
