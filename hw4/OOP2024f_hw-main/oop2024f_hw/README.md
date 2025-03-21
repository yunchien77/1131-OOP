# Homework 04
> 這份作業由物件導向程式設計助教群所製。 如有問題，歡迎使用以下方式聯繫助教： Email: t111590009@ntut.edu.tw.

⚠️ Due: 11:59 p.m., 13 / 12 / 2024 ⚠️

## 測題須知
在 `include/Config.hpp` 當中，有兩個巨集 `TESTING_TARGET2` 和 `TESTING_TARGET3`。他們預設的值為 false，當你完成了對應的目標二、目標三時，可以將其轉換為 `true`，已方便進行測題。

需要注意的是，請完成目標二、三的要求，再進行上傳。

## 說明
在這個任務中，你將基於 Minecraft 當中的礦物燒製原則，模擬出一個基本的架構。

你會有幾個基本的礦物，經過熔爐燒製之後，就會產生出產物和經驗值。當中你需要判斷礦物能不能被熔煉。

且為了之後的擴展性，你會需要先判斷是否礦物能被適當的工具挖起。

以下的題目敘述將會以抽象化、需求化的描述方式，因此你需要結合題目需求與項目內程式碼，自行理解實作內容。若有任何對於題目解讀不理解、意思不清晰、概念衝突等，歡迎使用 TA 的 email 進行提問。

> t111590009@ntut.edu.tw.

## 目標一、礦物實作

<!-- 放置 Ore 等繼承關係圖。 -->

- 父類（`Ore.hpp`）

  這個檔案裡面存放著名為 `Ore` 的類別，其為礦物的基礎類別。

  它會有幾個基本的原則，首先他會需要有該礦物被燒制之後的經驗值，以及被燒制之後的產物為何。當然為了封裝的有效性，我們只會讓他保持唯獨的狀態，除了被子類繼承的情況。

  在我們設計的原則下，礦物有兩種需要實作的功能是。第一，是否礦物能被傳入的工具挖掘。第二，是否該礦物能被燒制。

- 子類（`CoalOre.hpp`, `DiamondOre.hpp`, `GoldOre.hpp`, `IronOre.hpp`, `SmeltableOre.hpp`）
    子類在此處為礦物的子類別，在我們設計的原則當中包含：煤炭礦、鐵礦、鑽石礦、金礦。根據父類的說明，再觀察以下的表格，完成任務。
    
    

    | 礦物名稱 | 挖掘經驗    | 燒制經驗 | 燒制後成品 | 挖掘工具                       | 是否能被燒制 |
    | -------- | --- | -------- | ---------- |:------------------------------ | ------------ |
    | 煤炭礦   |  2.0   | 無     | 煤炭       | 木製、石製、鐵製、金製、鑽石製 | 否           |
    | 鐵礦     |   0  | 0.7      | 鐵         | 石製、鐵製、金製、鑽石製       | 是           |
    | 鑽石礦   |  4.0   | 無      | 鑽石       | 鐵製、金製、鑽石製             | 否           |
    | 金礦     |  0   | 1.0      | 黃金       | 鐵製、金製、鑽石製             | 是           |
    
    而你可以使用繼承類別 `SmeltableOre`，代表說只要繼承該類別後，礦物就能被熔爐燒制。反之如果有類別沒有繼承 `SmeltableOre` 則代表該礦物不能被燒制。
    
    
    
- 熔爐（`Furnace.hpp`）
  熔爐主要將礦物燒制成成品，並且你要判斷是否當前熔爐的存放的礦物已超過 64 個，則 `std::invalid_argument`。

  當然在拿起產物的部分，需要一次拿起熔爐所有的產物。

  在 Minecraft 當中，熔爐具有燃料值消耗的計算部分，但在我們作業當中，並不會有此概念出現在題目當中。

  在 Minecraft 當中，熔爐如果正在燒制礦物，那接下來都只能繼續燒制該類別的礦物。除非該礦物燒完了且已經從熔爐被取出，那才能繼續燒其他類別的東西。如果強行放置，只能 `std::invalid_argument`。

## 目標二、陣列實作與熔爐重作

- 陣列（`List.hpp`）
  該練習主旨為使用 `template` 的概念。

  在陣列當中我們只會重新包裝 `std::vector` 的所有行為，並不會重新實現 `vector` 的底層原理。特別提及的是 `T PopElement` 的功能中，你需要把陣列的最後一個值儲存起來到別處，使得後續能傳出，並且移除該值在陣列的地方。

  要注意的是，因為 `Template` 的實作在 C++ 有點不太一樣，因此他被放在 `include/List.inl`

- 熔爐（`Furnace.hpp`）
    你需要使用 Function overload 重新實現增加礦物到熔爐的功能。
    
## 目標三、熔爐再重作
- 熔爐（`Furnace.hpp`）
    你需要使用 Upcasting 重新實現增加礦物的熔爐功能。

    
# Homework's meme
![1732802112106](https://hackmd.io/_uploads/BJqPIeLmJl.png)

---