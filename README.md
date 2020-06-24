# Chat Server

## How to Run

1. 需要有 MySQL 环境

```shell
sudo apt install mysqlclient
```

2. 下载依赖

```shell
# uuid
sudo apt-get install uuid-dev
```

或者

```shell
./Dependence.sh
```

2. 修改配置文件，添加 MySQL 服务器的 IP， Port， Pass ward，User, DB等

```txt
dbip=127.0.0.1
dbuser=root
dbpsw=passwd
db=db_name
dbport=8806
```

3. 创建 表

```sql
CREATE TABLE `User` (
  `UID` char(15) NOT NULL,
  `PSW` varchar(255) NOT NULL,
  `addr` varchar(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  PRIMARY KEY (`UID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `Token` (
  `uid` char(15) NOT NULL,
  `token` varchar(36) NOT NULL,
  `create_time` datetime DEFAULT NULL ON UPDATE CURRENT_TIMESTAMP,
  KEY `uid` (`uid`),
  CONSTRAINT `uid` FOREIGN KEY (`uid`) REFERENCES `User` (`UID`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
```

4. 编译源代码

```shell
make
make clear
```

5. 运行

```shell
./server
```

## Thanks

[conf文件的读写](https://www.cnblogs.com/happyamyhope/p/10874024.html)
