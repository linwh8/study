# Computer Networks and the Internet

这个笔记是参照 Kurose 和 Ross 写著的 *Computer Network, A Top-Down Approach* 6th edition Chapter 1，配合这本书阅读效果更佳~

## Definition

End systems 由 communication links 和 packet switches 组成

- hosts: 终端
- communication links: 通信链路（铜线、光纤）。用bandwidth描述数据传输速度
- packets: 包。data + header = packets
- packet switches: 分组交换，路由器和交换机
- ISP (Internet Service Providers): 服务提供商，中国电信
- IP (Internet Protocol): 网络协议，制定路由与终端之间包的格式
- Protocol 协议定义了网络实体之间传送消息的规则，不同的协议有不同的作用

## The Network Edge

- client & server: 客户端和服务端都是end systems
- access network，接入网，**即连接终端系统和边缘路由器（即first-hop router）的物理连接**。关键性质是 **bandwidth** 和 **shared or dedicated**
  - residential，例如拨号上网（占用电话线的慢速上网），DSL（数字订阅线路，由电信服务商提供的快速网络。有快速、慢速、电话线三种平行线路，但是限制距离），HFC（混合光纤，共享上下行线路，不对称）
  - institutional，通常用LAN接入一个路由
  - wireless，无线网络
- physical media，物理介质
  - twisted-pair copper wire, 双绞铜线，便宜
  - coaxial cable，同轴电缆
  - fiber optics，光缆，高速高带宽

## The Network Core

主要有两种方式在网络links和switches之间传输数据：packet switching 和 circuit switching。Network core的两大核心功能是 **routing** 和 **forwarding**

### packet switching

**将应用层 messages 分解成 packets，接收方收到 packets 后再进行组装**。在source和destination之间通过communication links（物理连接）和packet switches（通常是路由器和链路层交换机）

- store-and-forward（存储转发）：packet switches 必须要收到整个packet之后才能forward这个packet的第一个bit。如果每个packets大小为$L$，传输速度为$R$，总共要经过$Q$个连接，那transmission time 为$Q · L/R$

- output buffer（输出缓冲）：每个packet switch连有多个link，对每个连接的link都有一个output buffer。当一个包到达link，发现link正在传输别的包，那他要在output buffer里面等处理完当前的包之后再发送。如果arrival rate比transmission rate高（处理的速度没有来的速度快），那packet loss会发生 

![](https://i.loli.net/2018/06/13/5b212bbb438be.png)

### circuit switching

每台主机都和一台 switches 直接连接，交换机之间互联，每条链路有n条电路，所以每条链路支持n条电路同时连接（因此一条communication links需要divided给不同的circuit）。**电路交换对电路利用率低，因为资源被预留，dedicated，只有用到的时候才发挥作用**。不过实时性很高

![](https://i.loli.net/2018/06/13/5b212be56b770.png)

### packet switching V.S. circuit switching

Circuit switching **pre-allocates** use of the transmission link regard-less of demand, with allocated but unneeded link time going unused.

Packet switching on the other hand allocates link use **on demand**

|      | Packet Switching                                             | Circuit Switching                                          |
| ---- | ------------------------------------------------------------ | ---------------------------------------------------------- |
| pros | 更好的分享传输能力、更简单有效                               | 为链路预留资源，链路可以在需要的时候就能快速稳定的获得资源 |
| cons | 服务多变不可预测（due primarily to variable and unpredictable queuing delays） | 效率低，并不是所有的用户都要时时刻刻用到这个资源           |

## ISP and Internet Backbones

- "tier-1" 商业ISP（中国电信）
- IXP（Internet exchange point）是不同ISP提供商之间的桥梁
- content provider network (Google)，亲自为用户提供服务

![](https://i.loli.net/2018/06/13/5b212c01e9597.png)

## Delay, Loss, Throughput in networks

### delay in packet-switched networks

- queuing delay，由于转发（transmit）速度比到达速度（arrival）慢，新来的packet要等待前面的packet被发出去的排队时间
- transmission delay，由于转发（transmit）需要时间，即把一个包从路由器推向物理链路，或者说一辆车经过收费站，需要时间，这个就是转发时间。转发延迟又叫store-and-forward delay，与路由器link bandwidth有关
- propagation delay，传播延迟。由于物理上的距离产生的延迟，两个路由器距离越远传播越久。而转发是路由器与link之间的延迟，与路线长短无关
- processing delay，路由器解析packet花的时间，与路由器本身性能有关

![](https://i.loli.net/2018/06/13/5b212c209e881.png)

一个节点处理的总时间$d_{total}$可以由下列公式得到

$$
d_{total} = d_{proc}+d_{queue}+d_{trans}+d_{prop}
$$

用一个比喻来说就是

![](https://i.loli.net/2018/06/13/5b212c3311347.png)

- car - bits
- caravan - packets
- toll booth - router
- link - road

每辆car过收费站要花时间，**整个车队**经过收费站的时间就是transmission delay，每辆car要等整个caravan到齐了再一起离开收费站，收费站之间的路有propagation delay

### queuing delay and packet loss

- $R$: link bandwidth (bps)
- $L$: packet length (bits)
- $a$: average packet arrival rate

所以$La$表示每秒钟来的bits数目，$R$表示每秒送出去的bits数目。如果$La/R>1$，表示来的速度快过走的速度，这样排队时间就无限长，队伍也无限长。如果满了就会发生丢包

### end-to-end delay

端到端指的是从source到destination的delay。对比下式和total nodal delay发现这里面少了queue delay，可能是假设全程畅通吧

$$
d_{end-end} = N(d_{proc}+d_{trans}+d_{prop})
$$

### throughput

throughput是实时的传播速度。比如F bits的文件通过T秒送到目的地，那average throughput就是$F/T$，bandwidth 是理想的传播速度，通常throughput比bandwidth小

- Scenario 1: client和server单条路线连通，client到路由器速度为$R_c$，server到路由器的速度为$R_s$，由于要流水线操作，不能上传速度大于下行速度，所以bottleneck在小的那个速度上，throughput = min{$R_s, R_c$}

- Scenario 2: 互联网情况，由于多个服务器和多个客户端连接，中间那个要共享，所以throughput = min{$R_s, R_c, R/10$}

![](https://i.loli.net/2018/06/13/5b212c64eb07f.png)

## Protocol Layers and Service Model

网络分成几个层次，每层有每层的功能和提供的服务。标准化组织的model有7层，Internet只有五层，少了Presentation和Session层。

- Application layer 提供高级应用服务，传输叫做 message 的信息
  - FTP、HTTP、DNS


- Transport layer，完成对应用层协议的信息的发送（端对端），接受来自 application layer 的 message，并把它分解成 segment
  - TCP: connection oriented, provides **reliable, in-sequence delivery of data** from **end-to-end** on behalf of application
  - UDP: connectionless, provides no-frills, **no reliability**, **no flow/congestion control** service
- Network layer，提供**“best-effort”, but unreliable** delivery，执行**路由和转发**，接受来自传输层的 segment 并把它分解成 datagram
  - IP Protocol，定义了 datagram 的格式，Internet 里所有的组件都要遵守这个规则来处理 datagram
  - routing protocol，选路协议
  - 网络层核心功能：路由和转发
- Link layer， carries data over (usually) **point-to-point** links between hosts and routers，接受来自网络层的 datagram 把它分解成 frame 传输
  - 不同 link 提供的协议不同，例如 Ethernet, Wi-Fi
- Physical layer，具体的物理线路，传输bits

额外的两层

- presentation：解释数据的含义，比如加密
- session：同步之类的

![](https://i.loli.net/2018/06/13/5b212c7c470e8.png)

每一层都有自己的header，从message，到segment，到datagram，到最后的frame，不断缩小