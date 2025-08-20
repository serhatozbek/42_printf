# 📚 ft_printf - 42 Kocaeli Projesi

### Bu repository, C dilindeki standart printf fonksiyonunun kendi implementasyonumu içerir. 42 müfredatının bir parçası olan bu proje, değişken sayıda argüman alan fonksiyonların (variadic functions) nasıl çalıştığını anlamak ve C dilindeki temel yetenekleri derinleştirmek amacıyla geliştirilmiştir.

## 🚀 Projenin Amacı

### ft_printf, orijinal printf fonksiyonunun temel davranışlarını taklit eder. Belirtilen format belirteçlerine göre ekrana çeşitli veri türlerini basabilen bir kütüphane oluşturmayı hedefler. Bu proje sayesinde C'de bellek yönetimi, pointer kullanımı ve değişken argümanlı fonksiyonlar gibi konularda yetkinlik kazanılmıştır.

---

## ✨ Desteklenen Format Belirteçleri

### Bu ft_printf implementasyonu aşağıdaki format belirteçlerini desteklemektedir:

```bash
# %c : Tek bir karakteri (char) basar.

# %s : Bir karakter dizisini (string) basar.

# %p : İşaretçinin (pointer) bellek adresini hexadecimal formatta basar.

# %d : Onluk tabanda bir tam sayıyı (decimal) basar.

# %i : Onluk tabanda bir tam sayıyı (integer) basar.

# %u : İşaretsiz onluk tabanda bir tam sayıyı (unsigned decimal) basar.

# %x : Onaltılık tabanda (hexadecimal) küçük harflerle bir sayıyı basar (a, b, c, d, e, f).

# %X : Onaltılık tabanda (hexadecimal) büyük harflerle bir sayıyı basar (A, B, C, D, E, F).

# %% : Yüzde (%) işaretini basar.
```
---

## 🛠️ Nasıl Kullanılır?

### Projeyi kullanmak için repository'yi klonlayın ve make komutunu çalıştırarak kütüphaneyi (libftprintf.a) derleyin.

```shell

# Repoyu klonla
git clone https://github.com/serhatozbek/42_printf.git

# Klasöre git
cd 42_printf

# Kütüphaneyi derle
make
```
---

## Kendi Projende Kullanım

### Oluşturulan libftprintf.a kütüphanesini ve ft_printf.h başlık dosyasını kendi projenize dahil edebilirsiniz. Kendi C dosyanızı derlerken kütüphaneyi bağlamayı unutmayın:

```c

// main.c dosyanızın içeriği
#include "ft_printf.h"

int main(void)
{
    char *str = "Dünya";
    int   num = 42;

    ft_printf("Merhaba, %s!\n", str);
    ft_printf("Cevap: %d\n", num);
    ft_printf("Hexadecimal: %x\n", 255);
    ft_printf("Pointer adresi: %p\n", &num);
    
    return (0);
}
```
### Derleme Komutu
```Bash

# -L. mevcut dizindeki kütüphaneyi arar
# -lftprintf ise libftprintf.a kütüphanesini bağlar
cc main.c -L. -lftprintf -o program
```

---

## ⚠️ Sorumluluk Reddi

### Bu repository'deki çözümler tamamen eğitim ve portföy amaçlıdır. 42'nin onur kuralları (honour code) gereği, Common Core sürecindeki öğrencilerin çözümleri kopyalaması kesinlikle yasaktır. Buradaki kodlar, repodaki projeyi tamamlamış biri olarak gelişimimi göstermek ve gelecekteki projelerim için bir referans noktası oluşturmak amacıyla paylaşılmıştır.

---