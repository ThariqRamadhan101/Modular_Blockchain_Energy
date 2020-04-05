# Modular_Blockchain_Energy

## Deskripsi

Repository ini merupakan bagian dari Tugas Besar matakuliah ET4043 Infrastruktur Blockchain. Tema yang kami dapatkan saat pembagian adalah ENERGY.Ide dari kelompok kami adalah membuat Modular Blockchain Energy, suatu sistem yang dapat mengatur penggunaan energy dengan blockhain dan menampilkan penggunaan energi pada browser. Kami berusaha membuat alat ini bekerja sebaik mungkin namun karena adanya pandemi COVID-19 dan keterbatasan biaya. Untuk diagram block dan schematic akan dibuat sesuai dengan sebenarnya. Namun untuk pengambilan data dari sensor kami menggunakan simulasi. Disimulasikan  device diletakkan disuatu rumah yang mempunyai beban dan baterai yang terhubung pada grid. Device akan membaca daya beban rumah tangga dan daya baterai.

## Dari keadaan sebenarnya menjadi simulasi 
Apabila ada yang tertarik untuk mempraktekan reposity ini menjadi keadaan sebanarnya bagian ini merupakan penjelasan bagaimana dari simulasi didapatkan dari keadaan sebenarnya.

Untuk mendapatkan energi yang dipakai oleh tegangan AC didapatkan dari formula berikut :

Energy_AC = Vrms * Irms * pf * time
- Vrms : Merupakan regangan root mean square rumah tangga untuk di Indonesia yaitu 220 Volt
- Irms : Didapatkan melalui sensor arus AC
- pf : Merupakan power factor diketahui biasanya 0.85
- time : Selang waktu penggunaan

Untuk mendapatakan energi baterai(DC) didapatkan dari formula berikut :

Energy_Battery = Vb * Ib * t
- Vb : Tegangan baterai terukut
- Ib : Arus baterai yang terukur keluar
- t : Selang waktu penggunaan

Pada simulasi tidak digunakan tegangan dan arus tapi langsung menggunakan energy. Dikarenakan tegangan dan arus dapat berubah-ubah sesuai beban yang digunakan oleh karana itu langsung digunakan energy. Kemudian digunakan beban dan baterai yang digunakan sesuai dengan penggunaan dan harga listrik di Indonesia. Dengan asumsi:
- Daya beban sebesar 325 Watt
- Baterai yang digunakan 12 Volt 100 Ah dengan batas tegangan kerja 14.4-14.9 Volt
- Solar panel memberikan daya ke bateri 0.5 Watt
- Harga listrik Rp 0.791 per Wh
- Ada delay perubahan state senilai 1 detik

## Device
 
### Diagram Block
![Diagram Block](https://raw.githubusercontent.com/ThariqRamadhan101/Modular_Blockchain_Energy/master/Blockchain.png)

### Schematic
![Schematic](https://raw.githubusercontent.com/ThariqRamadhan101/Modular_Blockchain_Energy/master/Schematic_Modular_Blockchain_Energy_Sheet_1_20200405102355.png)

### Deskripsi Program
Program ini terdiri 3 state yang on/off yaitu:
1. AC_ON : Simulasi ada daya AC yang digunakan
2. DC_ON : Simulasi penggunaan baterai(Tegangan baterai berkurang setiap waktu)
3. DC_CHARGE : Simulasi pengecasan baterai(Tegangan baterai naik setiap waktu)
  

## Kontributor
- 13216096 - Thariq Ramadhan
- 18116003 - Anneke Yolanda
- 18116022 - Aidil Firmansyah Putra

## Pembimbing
Wervyan Shalannanda ST,MT

