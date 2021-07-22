# wiidungeon.xml Enemy 'Name' Values

This table lists the enemy spawned by each `<name>` value (tribe id + 1) of an `<enemy>` entry in `wiidungeon.xml`. Values not listed are invalid and will crash the game.

* The `Template` column refers to the id of the NPCEnemyTemplate used
    * [NPCEnemyTemplate Struct Definition](https://github.com/SeekyCt/spm-docs/blob/master/headers/npcdrv.h)
    * [npcEnemyTemplates Table Dump](https://github.com/SeekyCt/spm-docs/blob/master/misc/npcenemytemplates.txt)
* `Used in Pit` shows whether this enemy type is used anywhere in `wiidungeon.xml`.
* `Template En Name` is a name for the template taken from [Skawo's Level Editor](https://github.com/skawo/Super-Paper-Mario-Level-Editor-Randomizer/blob/master/Super%20Paper%20Mario%20Randomizer/Jsons/Enemies.json)
    * These were manually documented by him, they're not translations of `Template JP Name`
* `Template JP Name` is the internal Japanese name for the template 

| Name | Template | Used in Pit | Template En Name (By Skawo) | Template JP Name |
|------|----------|-------------|-----------------------------|------------------|
1|2|True|Goomba|クリボー
2|5|True|Flip Goomba|ジゲンクリボー
3|329|True|Dark Goomba|カゲクリボー
4|235|True|Gloomba|ヤミクリボー
5|3|True|Spiked Goomba|トゲクリボー
6|6|False|Spiked Goomba|トゲクリボー（落ちない）
7|327|True|Dark Spiked Goomba|カゲトゲクリボー
8|4|True|Paragoomba|パタクリボー
9|328|True|Dark Paragoomba|カゲパタクリボー
10|84|True|Headbonk Goomba|ズツキクリボー
11|330|True|Dark Headbonk Goomba|カゲズツキクリボー
12|8|True|Green Koopa Troopa|ノコノコ
13|237|False|Glasses-less Koopa|ノコノコ（グラサンなし）
14|73|False|Glitchy Koopa|ノコノコ（無限増殖用）
15|9|True|Red Koopa Troopa|ノコノコ（赤）
16|12|True|Flip Red Koopa Troopa|ジゲンノコノコ
17|71|True|Glitchy Dark Koopa|カゲノコ
18|63|False|Mega Koopa|ボスノコノコ
19|11|True|Koopatrol|トゲノコ
20|331|True|Dark Koopatrol|カゲトゲノコ
21|14|True|Green Paratroopa|パタパタ
22|238|False|Glasses-less Paratroopa|パタパタ（グラサンなし）
23|15|False|Red Paratroopa|パタパタ（赤）
24|17|True|Flip Red Paratroopa|ジゲンパタパタ
25|333|True|Dark Paratroopa|カゲパタ
26|53|True|Buzzy Beetle|メット
27|54|False|Nothing?|メット（逆さ）
28|56|True|Spike Top|トゲメット
29|253|False|Spike Top|トゲメット（逆さ）
30|334|True|Dark Spike Top|カゲトゲメット
31|57|False|Parabuzzy|パタメット
32|58|False|Spiky Parabuzzy|パタトゲメット
33|96|True|Stone Buzzy|ストーンメット
34|335|True|Dark Stone Buzzy|カゲストーンメット
35|61|False|Lakitu|ジュゲム
36|62|False|Flip Lakitu|ジゲンジュゲム
37|59|True|Spiny|トゲゾー
38|99|True|Flip Spiny|ジゲントゲゾー
39|336|True|Dark Spiny|カゲトゲゾー
40|36|True|Dry Bones|カロン
42|38|True|Dull Bones|ホネノコ
44|337|True|Dark Dull Bones|カゲホネノコ
46|24|True|Hammer Bro.|ハンマーブロス
48|46|True|Flip Hammer Bro.|ジゲンハンマーブロス
50|339|True|Dark Hammer Bro|カゲハンマーブロス
52|39|True|Boomerang Bro|ブーメランブロス
54|310|True|Flip Boomerang Bro|ジゲンブーメランブロス
56|340|True|Dark Boomerang Bro|カゲブーメランブロス
58|40|True|Fire Bro|ファイアブロス
60|311|True|Flip Fire Bro|ジゲンファイアブロス
62|341|True|Dark Fire Bro|カゲファイアブロス
64|80|True|Magikoopa|カメック
65|81|True|Broom Magikoopa|カメック（ホウキ）
67|345|True|Dark Magikoopa|カゲカメック
68|346|True|Broom Dark Magikoopa|カゲカメック（ホウキ）
70|128|True|Koopa Striker|コウラシューター
72|268|False|Flip Koopa Stiker|ツインシューター
74|270|True|Soopa Striker|スーパーシューター
76|348|True|Dark Striker|カゲシューター
78|31|False|Piranha Plant|パックンフラワー
79|49|False|Putrid Piranha|ポイズンパックン
81|51|False|Frost Piranha|アイスパックン
83|106|False|Bullet Bill|キラー
84|107|False|Bill Blaster|キラーたいほう
85|110|True|Boo|テレサ
86|111|True|Dark Boo|ダークテレサ
87|366|True|Dark Dark Boo|カゲテレサ
88|112|False|Atomic Boo|アトミックテレサ
89|25|False|Green Cheep Cheep|プクプク
90|67|False|Red Cheep Cheep|プクプク（赤）
91|69|False|Flip Cheep Cheep|ジゲンプクプク
92|26|False|Blooper|げっそー
93|45|False|Flip Blooper|ジゲンげっそー
94|133|False|Bittacuda|フグモドキ
95|19|True|Clubba|ガボンへい
96|350|True|Dark Clubba|カゲガボンへい
97|117|True|Fuzzy|チョロボン
98|120|True|Pink Fuzzy|ピンクチョロボン
99|354|True|Dark Fuzzy|カゲチョロボン
100|77|True|Bald Cleft|シンノスケ
101|78|True|Moon Cleft|シンエモン
102|367|True|Dark Cleft|カゲエモン
103|126|True|Pokey|サンボ
105|127|True|Poison Pokey|ドクサンボ
107|355|True|Dark Pokey|カゲサンボ
109|70|False|Swooper|バサバサ
110|159|True|Ruff Puff|クモクモーン
112|357|True|Dark Ruff Puff|カゲクモーン
114|75|True|Spania|ハンニャー
115|359|True|Dark Spania|カゲハンニャー
116|217|True|Crazee Dayzee|パンジーさん
118|302|True|Amazee Dayzee|きらめくパンジーさん
120|351|True|Dark Dayzee|カゲのパンジーさん
122|28|False|Lava Bubble|バブル
123|65|True|Chain Chomp|ワンワン
124|216|True|Overworld Red Underchomp|レッドワンワン
125|365|True|Dark Chomp|カゲワンワン
126|250|True|Squiglet|テトラ
127|148|True|Squig|テトラポン
129|251|True|Squog|テトラドン
131|283|True|Squoinker|テトラゴン
133|369|True|Dark Squiglet|カゲテトラ
135|144|True|Sproing-Oing|ピョンピョン
137|289|True|Boing-Oing|ルリピョンピョン
139|291|True|Zoing-Oing|ハクピョンピョン
141|371|True|Dark Sproing-Oing|カゲピョンピョン
143|153|True|Boomboxer|オンパー
145|274|True|Beepboxer|ウェービー
147|294|True|Blastboxer|パルサー
149|373|True|Dark Boomboxer|カゲオンパー
151|100|False|Mister I|アイクン
153|280|False|Red I|きょうふのめだま
155|376|False|(Unused) Dark I|カゲめだま
157|147|True|Shlurp|バクー
158|301|True|Shlorp|ゴクー
159|368|True|Dark Shlurp|カゲバクー
160|164|True|Growmeba|ポイポイ
161|266|True|Blomeba|ポロポロ
162|267|True|Chromeba|ボロボロ
163|378|True|Dark Growmeba|カゲポイポイ
164|160|True|Tileoid G|タイールＧ
165|161|True|Tileoid B|タイールＢ
166|162|True|Tileoid R|タイールＲ
167|163|True|Tileoid Y|タイールＹ
168|379|True|Dark Tileoid |カゲタイール
169|141|True|Jawbus|ジャマドン
170|296|True|Rawbus|ジャマゴン
171|297|True|Gawbus|ジャマギラス
172|375|True|Dark Jawbus|カゲジャマドン
173|168|False|BigMeow|デカニャン
174|20|False|PatrolMeow|パトニャン
175|21|False|AirMeow|フライニャン
176|22|False|SurpriseMeow|ドカニャン
178|135|False|BombMeow|ボムニャン（リモコンタイプ）
179|170|False|Jellien|ジェルル
180|171|False|Foton|フォトン
182|172|False|Warpid|ワープワープ
183|169|False|Eeligon|フレーゴン
185|210|True|Hooligon|フレーゴンプラス
187|380|True|Dark Eeligon|カゲフレーゴン
189|97|True|Longator|カックン
190|273|True|Longadile|ガックン
191|382|True|Dark Longator|カゲカックン
192|154|True|Choppa|ヘリン
193|278|True|Copta|コプタ
194|386|True|Dark Choppa|カゲへリン
195|86|False|Barribad|バリバー
197|298|False|Sobarribad|チョバリバー
199|383|True|Dark Barribad|カゲバリバー
201|88|True|Pigarithm|ブーチョ
202|300|True|Hogarithm|トンチョ
203|385|True|Dark Pigarithm|カゲブーチョ
204|175|False|Floro Cragnon (Round)|ロック人（▽頭）
205|176|False|Floro Cragnon (Triangular)|ロック人（○頭）
206|239|False|Floro Sapien|ハナーン
208|243|False|Purple Floro Sapien|ハナーン（紫）
210|245|False|Red Floro Sapien|ハナーン（赤）
212|178|True|Ninjoe|ナンジャ
215|259|True|Ninjohn|チューナンジャ
218|262|True|Ninjerry|ジョーナンジャ
221|388|True|Dark Ninjoe|カゲナンジャ
224|194|True|Skellobit|ガイコッツ
225|312|True|Flip Skellobit|ジゲンガイコッツ
226|391|True|Dark Skellobit|カゲガイコッツ
227|195|True|Spiky Skellobit|トゲコッツ
228|313|True|Flip Spiky Skellobit|ジゲントゲコッツ
229|392|True|Dark Spiky Skellobit|カゲトゲコッツ
230|222|False|Skellobomber|ハネコッツ（頭タイプ）
231|315|False|Flip Skellobomber|ジゲンハネコッツ（頭タイプ）
233|221|False|Skellobomber w/Skellobait|ハネコッツ（運びタイプ）
234|314|False|Flip Skellobomber w/Skellobait|ジゲンハネコッツ（運びタイプ）
238|230|True|Blue Magiblot|アオマジール
240|229|True|Red Magiblot|アカマジール
242|231|True|Yellow Magiblot|キマジール
244|394|True|Dark Magiblot|カゲマジール
246|151|True|Slow Cursya|ノロイノロイ
247|206|False|Back Cursya|モドルノロイ
248|207|True|Tech Cursya|ワザノロイ
249|208|True|Heavy Cursya|オモイノロイ
250|209|True|Reversya Cursya|サカサノロイ
251|360|True|Dark Cursya|カゲノロイノロイ
252|362|True|Dark Tech Cursya|カゲワザノノロイ
253|363|True|Dark Heavy Cursya|カゲオモイノロイ
254|364|True|Dark Reversya Cursya|カゲサカサノロイ
255|152|False|Megabite|デスデス
256|265|False|Gigabite|デスデスデス
257|393|True|Dark Megabite|カゲデスデス
258|173|False|Muth|マンモー
259|293|False|Mega Muth|メガマンモー
260|387|True|Dark Muth|カゲマンモー
261|104|False|Howl|バンケン
262|105|False|Growl|ダイバンケン
263|247|False|Free Underhand|シロイテ（タイプ１）
264|248|False|Bound Underhand|シロイテ（タイプ２）
265|249|False|Disappearing Bound Underhand|シロイテ（タイプ３）
266|27|False|Thwomp|ドッスン
267|29|False|Spiny Tromp|ゴロン
268|47|False|Small Spiky Tromp|コロン
269|94|False|Zombie Shroom|キラーキノコ
270|272|False|Ghoul Shroom|ホラーキノコ
271|181|False|O'Chunks|ドドンタス（ＳＴＧ１）
272|182|False|O'Chunks|ドドンタス（ＳＴＧ５）
273|174|False|Veggiefied O'Chunks|ドドンタス（ＳＴＧ５・その２）
274|183|False|Giant O'Chunks|ドドンタス（ＳＴＧ８）
281|130|False|Mimi|マネーラ（ＳＴＧ２）
283|187|False|World 6 Mimi|マネーラ（ＳＴＧ６）
285|397|False|Mimi 2|マネーラ（ＳＴＧ８）
287|142|False|Dimentio|ディメーン（ＳＴＧ３）
288|405|False|Dimentio|ディメーン
290|225|False|Dimentio|ディメーン（ＳＴＧ５）
291|406|False|Dimentio|ディメーン（ＳＴＧ５）
293|226|False|Dimentio|ディメーン（ＳＴＧ８）
294|407|False|Dimentio|ディメーン（ＳＴＧ８）
296|137|False|Mr. L|ミスターＬ
297|138|False|Brobot|エルガンダー
301|188|False|Brobot L Type|エルガンダーＺ
306|196|False|Count Bleck|ノワール伯爵
310|255|False|Super Dimentio|スーパーディメーン
314|43|False|Fracktail|ズンババ
315|44|False|Wracktail|ザンババ
316|132|False|Bowser|クッパ
317|398|False|Bowser 2|クッパ(stg7)
318|136|False|Big Blooper|ダイオーげっそー
319|134|False|Francis|カメレゴン
320|150|False|King Croacus|キング・ハナーン
325|213|False|Overworld Underchomp (3)|ヘルワンワン
328|189|False|Bonechill|シニガミダス
331|287|False|Dark Mario|カゲマリオ
332|286|False|Dark Luigi|かげルイージ
333|288|False|Dark Peach|カゲピーチ
334|285|False|Dark Bowser|カゲクッパ
441|409|True|Cherbil|チェリリン
443|411|True|Poison Cherbil|ポイズンチェリリン
445|413|True|Ice Cherbil|アイスチェリリン
447|415|True|Dark Cherbil|カゲチェリリン
451|419|False|Frackle|コズンババR
452|420|False|Wrackle|コズンババ
454|422|False|Enemy Mario|HMGマリオ
455|423|False|Glitchy Enemy Mario|HMGマリオ
456|424|False|Enemy Luigi?|HMG_LUIGI
457|425|False|Enemy Luigi?|HMG_LUIGI
