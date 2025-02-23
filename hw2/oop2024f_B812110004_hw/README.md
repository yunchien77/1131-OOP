# Homework 02

###### tag: `homework`

> 這份作業由物件導向程式設計助教群所製。 如有問題，歡迎使用以下方式聯繫助教：
> Email: chenshiang@onon1101.org.

⚠️ Due: 11:59 p.m., 11 / 01 / 2024 ⚠️

## 作業目標

這份作業主要希望你能夠熟悉以下的事項，以利於跟進未來課程的發展：

- [x] 瞭解 Class 的使用方式
- [x] 學習封裝相關技巧。
- [x] 瞭解如何使用封裝進行解決方案的設計。
- [x] 更加瞭解類別的設計。

## 檔案架構

請確認提交是否符合以下的檔案架構，否則無法進行評分。

```
./
├── CMakeLists.txt
├── LICENSE
├── README.md
├── .gitignore
├── .clang-format
├── files.cmake
├── docs
│   └── hint.md
├── include
│   └── Vector.hpp
├── scripts
│   ├── CodeCoverage.cmake
│   └── coverage.sh
├── src
│   └── Vector.cpp
└── test
    └── ut_Vector.cpp
```

---

接下來我們會用到兩個檔案

```
 - Vector.hpp
 - Vector.cpp
```

## 題目敘述

> 在這個任務中，你將嘗試製作 `STL` 中的 `std::vector`

onon 是一位熱愛程式設計的工程師，他最近對 C++ 的資料結構產生了興趣，尤其對於 `std::vector` 這個容器充滿了好奇。onon 希望能夠透過實作一個`std::vector` 的陣列，來深入了解如何有效地管理和底層的實作原理。

onon 決定以存放整數型別資料的例子來進行。他的目標是建立一個可以儲存數字的陣列，其中每位陣列的位置都存放著不同的資料。類別當中的陣列會以一個的指標陣列來儲存資料，而這個指標應該由類別同一操作並管理，以便於可以簡單地訪問不同位置的資料。

給你一個 `Vector` 類別，在這個類別中，onon 希望能使用 `m_Data` 來儲存每筆數字，並且能夠提供多個方法來操作這些數字。例如，他希望能夠新增一筆數字並加入到陣列當中、查詢特定索引的數字、更新某個索引的數字。為了使程式更有彈性，onon 希望能夠實作一個方法來動態調整陣列的大小，並能夠自由地加入或移除特定的數字。

請確保完成以下的子任務，並以清晰的程式碼風格並通過單元測試來驗證你的程式是否符合 onon 的需求。

## 題目任務

### 第一階段、完成 `Vector` 類別，使類別包含以下的**私有成員**。
- #### `Vector.hpp`
    - `int m_Size = 0;`
      - 代表當前 `m_Data` 當中資料所佔的**筆數**。
    - `int m_Capacity = 0;`
      - 代表當前 `m_Data` 當中資料所能容納的**最大筆數**。
    - `int *m_Data = nullptr;`
      - 用於存放資料的陣列。

### 第二階段、完成 `Vector` 類別，使類別包含以下的 `getter`。
- #### `Vector.cpp`
    - `int GetSize() const;`
      - 用於回傳類別 `Vector` 當中成員 `m_Size` 資料的函數。
    - `int GetCapacity() const;`
      - 用於回傳類別 `Vector` 當中成員 `m_Capacity` 資料的函數。
### 第三階段、完成 `Vector` 類別，使類別包含以下的方法。
- #### `Vector.cpp`
    - `int At(int index) const;`
      - 就是從陣列 `m_Data` 中取得指定位置 `index` 的資料。
      - 如果 `index` 超過或者等於 `m_Size`，請 `throw std::out_of_range("[Class: Vector][Method: Join] message: out of range");`
    - `void Append(int value);`
      - 準備放置前，你需要檢查 `m_Capacity` 的空間是否足夠，如果不足就呼叫 `Resize();`。
      - 將 `value` 放置到陣列 `m_Data` 的**最後一個**位置。
      - 放置完成後，你需要增加 `m_Size` 的大小。
    - `void InsertAt(int index, int value);`
      - 如果 `index` 超過或者等於 `m_Size`，請 `throw std::out_of_range("[Class: Vector][Method: Join] message: out of range");`
      - 準備放置前，你需要檢查 `m_Capacity` 的空間是否足夠，如果不足就呼叫 `Resize();`。
      - 將指定位置 `index` 後的所有資料往後挪出一個空間，並在 `index` 的地方塞入 `value`。
      - 放置完成後，你需要增加 `m_Size` 的筆數。
    - `void UpdateAt(int index, int value);`
      - 如果 `index` 超過或者等於 `m_Size`，請 `throw std::out_of_range("[Class: Vector][Method: Join] message: out of range");`
      - 將指定位置 `index` 替換成數值 `value`。
    - `void RemoveAt(int index);`
      - 如果 `index` 超過或者等於 `m_Size`，請 `throw std::out_of_range("[Class: Vector][Method: Join] message: out of range");`
      - 刪除指定位置 `index` 的資料，並將 `index` 後的資料全部往前填滿已被刪除的位置。
      - 放置完成後，你需要減少 `m_Size` 的筆數，而 `m_Capacity` 保持不變。
    - `void Join(const Vector &other)`
      - 透過 `Append` 和 `At` 方法，將 `other.m_Data` 合併至 `m_Data` 的陣列內。
    - `void Resize();`
      - 用於重新擴充陣列 `m_Data` 的容量。
      - 如果成員 `m_Capacity` 為 `0`，請賦予初始值 `4`。其餘情況請將 `m_Capacity` 的大小擴充為兩倍。
      - 宣告一個指針 `int *tmp` 用於擴充新的陣列記憶體空間。e.g. `int *tmp = new int[m_Capacity];`
      - 在 `m_Data` 的資料重新搬移進入新的陣列 `*tmp`。
      - 刪除掉舊的記憶體空間 `delete[] m_Data;`
      - 把 `m_Data` 重新指向 `tmp`
        e.g. `m_Data = tmp;`
        
```cpp
// 以下你可以看到程式碼的結構大概會長的像這樣子：
void Vector::Resize() {
    // 定義 m_Capacity 的賦值
    /* 
     * your code...
     * 
     */
    
    // 新增動態記憶體
    int *tmp = new int[m_Capacity];
    
    // 將資料搬移進入新增的動態記憶體
    /* 
     * your code...
     * 
     */
    
    // 刪除舊有的記憶體
    delete[] m_Data;
    
    // 重新指向 tmp
    m_Data = tmp;
    
}
```

### 第四部分：在 Jenkins 上取得兩個 Job 的綠色勾勾。

- 在 jenkins.is1ab.com 通過助教的隱藏測試並取得兩個綠色勾勾。

## 作業知識

> 你會看到助教對於這份題目想更詳細說明的內容。

- [<p style="font-size: 22px;">如何使用 Git 上傳檔案至 Gitea - 重製篇</p>](./docs/git.md)
- [<p style="font-size: 22px;">在 HW2 當中，所引出的 Vector 的運作原理</p>](./docs/vector.md)


## Homework's meme

![1729177944760](https://hackmd.io/_uploads/H1gYKj0kJe.png)



