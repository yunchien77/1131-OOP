# LAB01 - Character Manager

> [!TIP]
> 在本次Lab中，我們的目標是製作一個簡易的遊戲。
> 並且在這次的Lab中學會基本的多型處理。

## 你所擁有的物件
### Printer
- Util
  - `void Draw(Point BlinkyPoint,Point InkyPoint,Point PinkyPoint,Point ClydePoint,Point PacmanPoint)` 會畫出整張 `16*16` 地圖，你不需要實作這個函數並請注意以下規則：
    - 對於 `Player` ，會輸出 `O`。
    - 對於 `Enemies` ，會輸出該 `Enemies` 輸出第一個大寫字母，像是 `Blinky` 會輸出 `B` 。
    - 關於 `Point` ，你可以參考 `Character.hpp` 內的 `struct Point` 。
    - $(0,0)$ 在左上角， $(15,15)$ 在右下角 。
    - 列印的 `Priority` 為 `Pacman` > `Clyde` > `Pinky` > `Inky` > `Blinky` 。

### Enemies
- Blinky
  - 行為：移動順序為 $(0,0)$ -> $(0,15)$ -> $(15,15)$ -> $(0,0)$ ，如此循環。
  - 每次移動 `3` 點，依照現有方向進行移動。
  - 起始位置在 $(0,0)$ 。
- Inky
  - 行為：移動順序為 $(0,0)$ -> $(15,15)$ -> $(0,0)$ ，如此循環。
  - 每次移動 `x` 與 `y` 各 `3` 點。
  - 起始位置在 $(15,15)$ 。
- Pinky
  - 行為：移動順序為 $(0,15)$ -> $(15,0)$ -> $(0,15)$ ，如此循環。
  - 每次移動 `x` 與 `y` 各 `3` 點。
  - 起始位置在 $(0,15)$ 。
- Clyde
  - 行為：根據 `Pacman` 目前的位置與 `Clyde` 為參考，若為水平或垂直，則移動單一座標軸兩個單位距離，否則對兩個座標移動三個單位距離。
  - 例如， `Player` 在 $(0,0)$ ， `Clyde` 在 $(5,0)$ ，則 `Clyde` 的 `x` 移動 `-2` 。
  - 例如， `Player` 在 $(0,0)$ ， `Clyde` 在 $(5,5)$ ，則 `Clyde` 的 `x` 移動 `-3` 、 `y` 移動 `-3` 。
  - 起始位置在 $(7,7)$ 。

#### Player

- Pacman
  - 行為模式如下所述 。

> [!TIP]
> `Pacman` 可以有以下操作
> - `W` ， `y` 增加 `3` 。
> - `A` ， `x` 減少 `3` 。
> - `S` ， `y` 減少 `3` 。
> - `D` ， `x` 增加 `3` 。
> - 你應該使用 `std::cin` 實現以上操作。
> `Pacman` 起始位置在 $(10,10)$ 。

> [!WARNING]
> 關於本次Lab，你應該要思考如何繼承並且使用 `Object Casting` 達成 `Inclusion` 。
> 當然在 `Derived Class` 裡面，你應該要先撰寫好 `建構子` ，並且覆寫掉純虛擬函數。
> 針對個別的角色，你可以自行設定 `function` 以及 `variable` 去達成任務目標。

## 題目敘述


> [!NOTE]
> 你在一個 $16 * 16$ 大小的棋盤，且你可以選擇一個方位進行移動。
> 你的目標就是在 $50$ 次的移動過程中，不要被四隻怪物給摸到。
> 棋盤自 $(0,0)$ 至 $(15,15)$。

## 運作流程

> [!NOTE]
> 這是一個回合制遊戲，流程如下。
> 1. `Pacman` 移動。
> 2. `Enemy` 移動。
> 3. `Manager` 判斷 `Pacman` 是否與任意 `Enemy` 碰撞。
> 4. 根據結果進行輸出。
> 以上重複 `50` 次。
> 若任一次執行結果 `Enemies` 與 `Pacman` 有碰撞則 `Pacman` 輸，反之則 `Pacman` 贏。
## 限制

> [!CAUTION]
> 任意角色不可以逃出棋盤。
> 也就是不得使 `x` 或 `y` 小於 `0` 或 大於 `15` 。
> 若下次移動會超出範圍，則設置為 `0` 或 `15` 。
> 也就是小於 `0` 設成 `0` ， 大於 `15` 設成 `15` 。

## 開放性任務

> [!IMPORTANT]
> - 修改除了 `Clyde` 以外的角色行為，或是新增一隻角色，使得任意一隻 `Enemy` 可以抓到 `Player` 。

> [!IMPORTANT]
> - 修改 `Player` 的行為使得 `Player` 不會被任意一隻 `Enemy` 抓到。
 
> [!NOTE]
> - 以上挑戰二選一進行，且不強迫。
> - 挑戰仍須遵守限制區的規則。
> - 完成挑戰可以獲得額外 `10` 分。

## 評分標準

- 100分
  - 使用繼承以及多形方法 (20分) 。
  - 正確的描述你們的程式邏輯及概念 (20分) 。
  - 完成Lab的基礎部分 (60分) 。
- 額外分數
  - 完成開放性任務 (10分) 。
- 你不需要將檔案推至 `gitea` ，只需要在寫完之後請助教評測。