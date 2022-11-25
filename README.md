# Calculating Discount Rate using Takagi and Sugeno’s Approach
<h2><b>Problem Statement:</b></h2>
Finding how much discount should a shopping website offer on a product on the basis of factors like <b>demand</b>, <b>availability</b> and <b>date of manufacturing</b> of the product and using fuzzy logic and Takagi and Sugeno’s Approach, given that the maximum discount that can be offered is 60%.

<h2><b>Introduction:</b></h2>
Shopping websites like Myntra have algorithms to decide how much discount should they offer on a given product. The algorithms consider several factors, a few of them being:
<ol>
<li>demand of the product in the market - 
<ul>
<li>higher the demand, lower will be the discount offered for the product and vice versa.</li>
</ul>
</li>
<li>stock available with the seller - 
<ul>
<li>if the stock available with the seller is high, the seller should offer higher discount and vice versa.</li>
</ul>
</li>
<li>lead time in the warehouse -
<ul>
<li>Consider a new product in the market then the seller would not offer much discount to it even if its demand is quite low or its stock available with the seller is abundant. This is because, newer product may take some time to grasp the market and for the consumer to get to know about it.</li>
</ul>
</li>
</ol>

<h2><b>Solution (Takagi & Sugeno):</b></h2>
We are taking three inputs to the program, I<sub>1</sub>, I<sub>2</sub> and I<sub>3</sub>, representing market demand, available stock and lead time of the product respectively.

<b><h4>First Input, I<sub>1</sub>:</h4></b>
<ul>
<li>Represents demand</li>
<li>
Linguistic terms used and coefficient for each linguistic term, in I<sub>1</sub>:
<ul>
<li>for sales 0 to 20: “VLOW” ; a<sub>1</sub> = 1</li>
<li>for sales 0 to 100: "LOW"; a<sub>2</sub> = 2</li>
<li>for sales 20 to 200: "MID"; a<sub>3</sub> = 3</li>
<li>for sales 100 to 200: "HIGH"; a<sub>4</sub> = 5</li>
</ul>
</li>
<li>Note that any sales higher than 200 will be taken as "HIGH" with membership value 1.</li>
<li>This input is different than other inputs since the output is inversely related unlike other inputs. And due to this reason we have normalized it as I<sub>1</sub> = 200 - I<sub>1</sub> (after calculating membership value for it).</li>
<li>Here is the graph for membership value vs number of sales for different linguistic terms</li>
<div>
<img src="https://i.postimg.cc/y8vt9sVR/image.png" width="900"/>
</div>
</ul>

<b><h4>Second Input, I<sub>2</sub>:</h4></b>
<ul>
<li>Represents available stock</li>
<li>
Linguistic terms used and coefficient for each linguistic term, in I<sub>2</sub>:
<ul>
<li>for stock 0 to 20: "HF" standing for HandFul, b<sub>1</sub> = 1</li>
<li>for stock 0 to 250: "SM" standing for SMall, b<sub>2</sub> = 3</li>
<li>for stock 20 to 500: "MID", b<sub>3</sub> = 5</li>
<li>for stock 250 to 500: "BK" standing for BulK, b<sub>4</sub> = 5</li>
</ul>
</li>
<li>Note that stocks bigger than 500 will be taken as "BK" with membership value 1.</li>
<li>Here is the graph for membership value vs no. of sales for different linguistic terms in I<sub>2</sub></li>
<div>
<img src="https://i.postimg.cc/Prh8vkVT/image.png" width="900"/>
</div>
</ul>

<b><h4>Third Input, I<sub>3</sub>:</h4></b>
<ul>
<li>Represents how old/new the product is.</li>
<li>
Linguistic terms used and coefficient for each linguistic term, in I<sub>3</sub>:
<ul>
<li>for stock 0 to 6 months old: "NEW", c<sub>1</sub> = 1</li>
<li>for stock 0 to 24 months old: "OLD", c<sub>2</sub> = 3</li>
<li>for stock 6 to 24 months old: "VOLD", c<sub>3</sub> = 5</li>
</ul>
</li>
<li>Products older than 24 months will considered "VOLD" with membership value 1.</li>
<li>Here is the graph for membership values vs no. of sales for different linguistic terms in I<sub>3</sub></li>
<div>
<img src="https://i.postimg.cc/wxW7MsNc/image.png" width="900"/>
</div>
</ul>

<h2><b>References:</b></h2>
<ul>
<li>For Takagi and Sugeno’s Algorithm - K. Pratihar, Dilip. Soft Computing Fundamentals and Applications. Alpha Science International Ltd.</li>
</ul>
