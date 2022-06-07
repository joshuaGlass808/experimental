# (Small) Binary string to int conversion in PHP.

Here were some interesting results when comparing it with php's native bindec method:
- I know, im not handling any edge cases like bindec may be handling.
- deal with it. (results will be added in later)
```
experimental/rust/bin-to-num % time ./target/release/rbenchmark
./target/release/rbenchmark  0.00s user 0.00s system 59% cpu 0.006 total

experimental/php/bin-to-num % time php bindec.php     
php bindec.php  0.02s user 0.02s system 88% cpu 0.035 total

experimental/php/bin-to-num % time php bin-to-int.php
php bin-to-int.php  0.02s user 0.01s system 89% cpu 0.040 total
```
