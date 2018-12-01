#pragma once

// ���������� ������ SameType � ����� ��������
// �����������. � ������� ������ ���� ����������
// ���� ����������� ��������� ���� bool � ������
// value

template <typename T, typename U>
struct SameType {
	static bool const value = false;
};

template <typename T>
struct SameType<T, T> {
	static bool const value = true;
};
