#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <bits/stdc++.h>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << '[';
    for (size_t i = 0; i < v.size(); i++) {
        os << v[i];
        if (i + 1 < v.size()) os << ", ";
    }
    return os << ']';
}

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

template<typename T, size_t N>
ostream& operator<<(ostream& os, const array<T, N>& a) {
    os << '[';
    for (size_t i = 0; i < N; i++) {
        os << a[i] << (i + 1 < N ? ", " : "");
    }
    return os << ']';
}

template<typename T>
ostream& operator<<(ostream& os, span<T> s) {
    os << '[';
    for (size_t i = 0; i < s.size(); ++i) {
        os << s[i] << (i + 1 < s.size() ? ", " : "");
    }
    return os << ']';
}

template<typename T, typename Cmp, typename Alloc>
ostream& operator<<(ostream& os, const set<T, Cmp, Alloc>& s) {
    os << '{';
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    return os << '}';
}

template<typename K, typename V, typename Cmp, typename Alloc>
ostream& operator<<(ostream& os, const map<K, V, Cmp, Alloc>& m) {
    os << '{';
    bool first = true;
    for (const auto& [key, val] : m) {
        if (!first) os << ", ";
        first = false;
        os << key << ": " << val;
    }
    return os << '}';
}

#define TO_STRING(x)    TO_STRING2(x)
#define TO_STRING2(x)   #x

#if defined(__clang__) || defined(__GNUC__)
  #define DBG_POS "[" "line " TO_STRING(__LINE__) "]"
#else
  #define DBG_POS "[" "line " TO_STRING(__LINE__) "]"
#endif

#ifdef _DEBUG

void debug_impl(stringstream& /* names */) {}

template<typename T, typename... Ts>
void debug_impl(stringstream& names, const T& head, const Ts&... tail) {
    string name;
    getline(names, name, ','); // Extrai o nome da variável da string
    
    name.erase(0, name.find_first_not_of(" \t\n\r"));
    name.erase(name.find_last_not_of(" \t\n\r") + 1);

    cerr << name << " = " << head; // Imprime "nome = valor"

    if constexpr (sizeof...(tail) > 0) {
        cerr << ", ";
        debug_impl(names, tail...);
    }
}

template<typename... Ts>
void debug_print(string_view names_sv, Ts&&... values) {
    cerr << DBG_POS << " ";
    stringstream names_ss;
    names_ss << names_sv; // Usa stringstream para facilitar a extração dos nomes
    debug_impl(names_ss, values...);
    cerr << '\n';
}

#define dbg(...) \
    debug_print(#__VA_ARGS__, __VA_ARGS__)


#else

#define dbg(...) ((void)0)

#endif // _DEBUG

#endif // DEBUG_HPP
