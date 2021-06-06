#pragma once

/**
 * Gunakan konstanta ini untuk perhitungan yang melibatkan pi.
 * Tidak usah mendeklarasikan lagi.
 */
const float pi = 3.14f;

/**
 * @brief Tipe data lingkaran
 */
struct Lingkaran {
  float jari;
};

/**
 * @brief Tipe data silinder
 */
struct Silinder {
  float tinggi;
  Lingkaran lingkaran;
};

/**
 * @brief Tipe data balok
 */
struct Balok {
  float p;
  float l;
  float t;
};