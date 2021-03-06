#pragma once
#include <vector>
#include <set>
#include <string>
#include <string_view>

namespace ConsoleWizard
{
	// ������� ����� ���������� �� ����� �����
	class Stream
	{
	private:
		// ������� �����
		size_t Counter = 0;

		// �������� ���� ���
		friend Stream &tab(Stream &s);

		// ������� ���� ���
		friend Stream &untab(Stream &s);

	public:
		// �������� ������� �������� ����������� �����
		std::string Spaces() const;

		// ������� ������ �������
		Stream &ReadLine(std::string &s);

		// ���������� ������� ������
		Stream();
	};

	// ������� ������ ����� � ������
	extern Stream io;

	// ������������� ������������

	Stream &wait(Stream &s);

	Stream &tab(Stream &s);

	Stream &untab(Stream &s);

	Stream &endl(Stream &s);

	Stream &tabl(Stream & s);

	Stream &untabl(Stream &s);

	// ���������� ������

	Stream &operator<<(Stream & s, Stream &(f)(Stream&));

	Stream &operator<<(Stream &s, const std::string_view &str);

	Stream &operator<<(Stream &s, const char &ch);

	Stream &operator<<(Stream &s, const unsigned long long int &n);

	Stream &operator<<(Stream &s, const long double &n);

	Stream &operator<<(Stream &s, const double &n);

	Stream &operator<<(Stream &s, const int &n);

	Stream &operator<<(Stream &s, const long long int &n);

	template<typename T> Stream &operator<<(Stream &s, const std::vector<T> &v)
	{
		s << "{" << tabl;
		for (const auto &i : v)
		{
			s << i << endl;
		}
		s << untab << "}" << endl;
		return s;
	}

	template<typename T> Stream &operator<<(Stream &s, const std::set<T> &v)
	{
		s << "{" << tabl;
		for (const auto &i : v)
		{
			s << i << endl;
		}
		s << untab << "}" << endl;
		return s;
	}

	template<typename T, typename CMP> Stream &operator<<(Stream &s, const std::set<T, CMP> &v)
	{
		s << "{" << tabl;
		for (const auto &i : v)
		{
			s << i << endl;
		}
		s << untab << "}" << endl;
		return s;
	}

	// ���������� �����

	Stream &operator>>(Stream &s, std::string &str);

	Stream &operator>>(Stream &s, char &ch);

	Stream &operator>>(Stream &s, double &n);

	Stream &operator>>(Stream &s, long double &n);

	Stream &operator>>(Stream &s, unsigned long long int &n);

	Stream &operator>>(Stream &s, int &n);

	Stream &operator>>(Stream &s, long long int &n);

	template<typename T> Stream &operator>>(Stream &s, std::vector<T> &v)
	{
		for (auto &i : v)
		{
			s >> i;
		}
		return s;
	}

	// ��� ���� ������ �����
	template<typename T> T Input()
	{
		T res;
		io >> res;
		return res;
	}

	class Procedure
	{
	private:
		const std::string Name;

	public:
		Procedure(const std::string_view &s);

		~Procedure();
	};
}