
#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector {
public:
    Vector() = default;
    Vector(const Vector &other);
    Vector(Vector &&other) noexcept;

    friend void swap(Vector &v1, Vector &v2);

    Vector &operator=(const Vector &other);
    Vector &operator=(Vector &&other) noexcept;

    ~Vector();

    int GetSize() const;
    int GetCapacity() const;

    int At(int index) const;

    void Append(int value);
    void InsertAt(int index, int value);
    void UpdateAt(int index, int value);
    void RemoveAt(int index);
    void Join(const Vector &other);

private:
    /* Vector成員 */
    int m_Size = 0;     // 當前 m_Data 當中資料所佔的筆數
    int m_Capacity = 0; // 當前 m_Data 當中資料所能容納的最大筆數
    int *m_Data = nullptr; // 用於存放資料的陣列

private:
    void Resize();
};

#endif