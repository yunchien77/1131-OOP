# OOP2023f Midterm

## 考試資訊

|   項目   |       內容       |
| :------: | :--------------: |
| 考試科目 | 物件導向程式設計 |
| 考試日期 |    2023/11/10    |
| 考試時間 |   18:30-21:00    |

## 專案架構

```
│  OOP 2023[F] Midterm.pdf                            // 題目
│  README.md                                          // 考試內容、考試規則與考試注意事項
│
└─material                                            // 考試素材（專案）
    │  .clang-format
    │  .gitignore
    │  CMakeLists.txt
    │  files.cmake
    │  LICENSE
    │
    ├─include
    │      AmarettoSour.h
    │      CowboyShot.h
    │      CraftBeer.h
    │      Fireball.h
    │      Goldschlager.h
    │      Hefeweizen.h
    │      IPA.h
    │      Lager.h
    │      Margarita.h
    │      Martini.h
    │      Tequila.h
    │      Wildfire.h
    │
    ├─scripts
    │      CodeCoverage.cmake
    │      coverage.sh
    │
    ├─src
    │      AmarettoSour.cpp
    │      CowboyShot.cpp
    │      CraftBeer.cpp
    │      Fireball.cpp
    │      Goldschlager.cpp
    │      Hefeweizen.cpp
    │      IPA.cpp
    │      Lager.cpp
    │      Margarita.cpp
    │      Martini.cpp
    │      Tequila.cpp
    │      Wildfire.cpp
    │
    └─test
            ut_CheckPoint1.cpp
            ut_CheckPoint2.cpp
            ut_CheckPoint3.cpp
```



## 考試相關規則

- 本次考試為「實體考試」，考試時間為 18:30-21:00，你應該「人到場」考試，若你有不得已的情形一定要遠距考試，請私訊說明。

- 呈上點，若使用學校電腦的同學，助教會幫忙安裝考試環境，預期安裝 CLion 與 Visual Studio Code 的考試環境。

- 考試可以帶自己的筆記，可以參考 `Gitlab` 上的資源，可以參考你放在 `Gitlab` 上的資源或 Coding Session 的內容。

- 呈上點，簡報將會提供在 `Gitlab` 上，你可以不用開 Teams 去下載這些簡報。

- 考試將提供測試資料，覆蓋率 100%，可以不用自己寫測試資料， `HW Job` 不計分。

- 呈上點，我們將提供三個資料，分別是 `ut_CheckPoint1.cpp`、`ut_CheckPoint2.cpp` 與 `ut_CheckPoint3.cpp`，在考試期間時，你可以視實作情況來0決定要只使用 `ut_CheckPoint1.cpp`，或是三個測試資料都使用，甚至只使用部分的測試資料來進行測試。基本上只要你能夠通過所有的測試，沒有意外的話會拿到上機考的 100 分。

- 考試期間，須開啟 Teams 會議並進行螢幕錄影。

- 無論如何都能跑出成績，務必在上機考結束前確認自己的上機考成績。



## 考試提問

- 請問「是非」相關的問題，我們會回答「對」或「不對」，或「沒有辦法回答」。
  - 正確範例：請問考試要按照檔案架構嗎。
    - 答案：對。
  - 錯誤範例：請問這個測資為什麼沒有通過。



## 考試前
- 請先清空個人專案。

  - 到你的個人專案資料夾，如果你沒有，`Clone` 一份（`git clone git@gitlab.is1ab.com:{學號}/oop2023f_{學號}_hw.git`）。

  - `git rm -rf *`

  - `git commit -m "Clean the project"`

  - `git push`

  - 確保你的專案是空的。

    ![image-20231110120137745](https://i.imgur.com/CDI1Hg1.png)

- 將考試所需素材移至個人專案。

  - 下載考試所需素材。

    ![image-20231110114556498](https://i.imgur.com/kvRmgND.png)

  - 將檔案挪至個人專案。

    ![image-20231110121235594](https://i.imgur.com/ltk5byP.png)

  - 你可以嘗試 Configure 專案，應該會出現以下的錯誤訊息。

    ![image-20231110121502172](https://i.imgur.com/inU2KzC.png)

    這是正常的（見題目任務一），接著你就能開始考試了。



## 考試注意事項

- **如果你要 `cmake` 任何檔案，請在 `files.cmake` 進行調整。**

  - 見 `files.cmake`，你可以自由新增檔案（例如新增 `src` 裡面的 `Mojito.cpp` 或調整 `test` 的 `ut_CheckPoint1.cpp`）
  - 在 Build 時將會讀取這些檔案。

- **你必須要確保 `CMakeLists.txt` 中的 `add_executable` 段落與下面範例相符。**

  ```cmake
  add_executable(ut_all
      ${SRC_FILES}
      ${INCLUDE_FILES}
      ${TEST_FILES}
  )
  ```

  如同上述的範例，而不是以下的範例。

  ```cmake
  add_executable(ut_all
      ${SRC_FILES}
      ${INCLUDE_FILES}
      ${TEST_FILES}
      BlaBlaBla.cpp
  )
  ```

