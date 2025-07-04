# fract-ol

42Tokyoの課題として作成したフラクタル描画プログラムです。MiniLibXを使用してマンデルブロ集合とジュリア集合を美しく描画します。

## 概要

このプログラムは以下のフラクタルを描画できます：
- **マンデルブロ集合 (Mandelbrot Set)**
- **ジュリア集合 (Julia Set)**

リアルタイムでズーム・移動が可能で、インタラクティブにフラクタルを探索できます。

## 機能

- 🎨 高品質なフラクタル描画
- 🔍 マウスホイールによるズーム機能
- ⌨️ キーボードによる移動とズーム操作
- 🖱️ マウスクリックによるズーム
- 📐 ジュリア集合のパラメータ指定

## コンパイル方法

```bash
# 通常版のコンパイル
make

# ボーナス版のコンパイル
make bonus

# クリーンアップ
make clean
make fclean
```

## 使用方法

### マンデルブロ集合

```bash
./fractol Mandelbrot
# または
./fractol M
```

### ジュリア集合

```bash
./fractol Julia <実数部> <虚数部>
# または
./fractol J <実数部> <虚数部>
```

パラメータは-2.0から2.0の範囲で指定してください。

#### おすすめのジュリア集合パラメータ

```bash
./fractol Julia -0.70176 -0.3842
./fractol Julia -0.8 0.156
./fractol Julia 0.3 0.01
./fractol Julia 0.45 0.35
```

## 操作方法

- **ズーム**: マウスホイール または `z`/`x` キー
- **移動**: 矢印キー
- **終了**: `ESC` キーまたはウィンドウの×ボタン

## プロジェクト構造

```
fract-ol/
├── Makefile
├── mandatory/          # 必須課題のソースコード
│   ├── fractol.h
│   ├── main.c
│   ├── render.c
│   ├── key_event.c
│   ├── mouse_event.c
│   ├── validate.c
│   ├── init.c
│   ├── ft_atof.c
│   └── print_msg.c
├── bonus/              # ボーナス課題のソースコード
│   └── ...
└── libft/              # 自作ライブラリ
    └── ...
```

## 技術仕様

- **言語**: C
- **グラフィックライブラリ**: MiniLibX
- **画面サイズ**: 1000x1000ピクセル
- **コンパイラフラグ**: -Wall -Wextra -Werror

## 学習内容

この課題を通じて以下を学習しました：

- 複素数とフラクタル数学の理解
- MiniLibXを使ったグラフィック描画
- イベントハンドリング（キーボード・マウス）
- 効率的な数値計算とレンダリング最適化
- メモリ管理とリソース管理
