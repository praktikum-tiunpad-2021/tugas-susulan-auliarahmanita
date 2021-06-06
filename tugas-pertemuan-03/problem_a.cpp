#include "shape.hpp"
#include "problem_a.hpp"

Lingkaran *new_lingkaran(float jari_jari) {
  Lingkaran *circle = new Lingkaran;
  circle->jari = jari_jari; 
  return circle;
}
Silinder *new_silinder(const Lingkaran &l, float tinggi) {
  Silinder *sili = new Silinder;
  sili->tinggi = tinggi;
  sili->lingkaran = l;
  return sili;
}
void new_silinder(Silinder *s, float jari_jari, float tinggi) {
  s->lingkaran.jari = jari_jari;
  s->tinggi = tinggi;

}
void new_balok(Balok *b, float panjang, float lebar, float tinggi) {
  b->p = panjang;
  b->l = lebar;
  b->t = tinggi;

}
float cari_diameter(const Lingkaran &l) {
  float diameter, jari;

  jari = l.jari;
  diameter = 2*jari;
  return diameter;
}
float cari_diameter(const Silinder &s) {
  return s.lingkaran.jari*2;
}
float cari_keliling(const Lingkaran &l) {
  float jari, keliling;
  jari = l.jari;
  keliling = 2*pi*jari;
  return keliling;
}
float cari_keliling(const Silinder &s) {
  return cari_diameter(s)*pi;
}
float cari_luas(const Lingkaran &l) {
  float jari, luas;
  jari = l.jari;
  luas = pi*jari*jari;
  return luas;
}
float cari_luas(const Silinder &s) {
  return cari_luas(s.lingkaran);
}
float cari_luas(const Balok &b) {
  float p,l,t,luas;
  
  p = b.p;
  l = b.l;
  t = b.t;
  luas = 2*(p*t + p*l + t*l);
  return luas;
}
float cari_volume(const Silinder &s) {
 return cari_luas(s.lingkaran)*s.tinggi;
}
float cari_volume(const Balok &b) {
  float p,l,t,volume;
  p = b.p;
  l = b.l;
  t = b.t;
  volume = p*l*t;
  return volume;
}