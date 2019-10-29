
-- MySQL dump 10.13  Distrib 5.1.66, for redhat-linux-gnu (x86_64)
--
-- Host: mysql.eecs.oregonstate.edu    Database: CS340
-- ------------------------------------------------------
-- Server version	5.1.65-community-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;


--
-- Table structure for table `club`
--
DROP TABLE IF EXISTS `club`;
CREATE TABLE `club`(
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `name` varchar(100) NOT NULL,
    PRIMARY KEY (`id`)
)ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `club`
--

LOCK TABLES `club` WRITE;
/*!40000 ALTER TABLE `club` DISABLE KEYS */;
INSERT INTO `club` VALUES (1,'Arsenal'),(2,'Malmo FC'),(3,'Athletico Madrid'),(4,'Roma'),(5,'Paris Saint Germain');
/*!40000 ALTER TABLE `club` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `cashflow`
--
DROP TABLE IF EXISTS `cashflow`;
CREATE TABLE `cashflow`(
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `club_id` int(11),
    `year` smallint(2) NOT NULL,
    `amount` int(11) NOT NULL DEFAULT 0,
    PRIMARY KEY (`id`),
    CONSTRAINT `cashflow_club` FOREIGN KEY (`club_id`) REFERENCES `club` (`id`)  ON DELETE CASCADE ON UPDATE CASCADE
)ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `cashflow`
--

LOCK TABLES `cashflow` WRITE;
/*!40000 ALTER TABLE `cashflow` DISABLE KEYS */;
INSERT INTO `cashflow` VALUES (1,1,2005, 100000),(2,1,2005, -100000),(3,2,2010, 12345),(4,2,2011, 678910);
/*!40000 ALTER TABLE `cashflow` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `country`
--
DROP TABLE IF EXISTS `country`;
CREATE TABLE `country`(
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `name` varchar(255) NOT NULL,
    PRIMARY KEY (`id`) 
)ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `country`
--

LOCK TABLES `country` WRITE;
/*!40000 ALTER TABLE `country` DISABLE KEYS */;
INSERT INTO `country` VALUES (1,"England"),(2,"Sweden"),(3,"Spain"),(4,"Italy"),(5,"France");
/*!40000 ALTER TABLE `country` ENABLE KEYS */;
UNLOCK TABLES;


--
-- Table structure for table `league`
--

DROP TABLE IF EXISTS `league`;
CREATE TABLE `league`(
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `name` varchar(255) NOT NULL,
    `country_id` int(11) DEFAULT NULL,
    PRIMARY KEY (`id`), 
    CONSTRAINT `league_country` FOREIGN KEY (`country_id`) REFERENCES `country` (`id`)  ON DELETE SET NULL ON UPDATE CASCADE
)ENGINE=InnoDB DEFAULT CHARSET=latin1;


--
-- Dumping data for table `league`
--
LOCK TABLES `league` WRITE;
/*!40000 ALTER TABLE `league` DISABLE KEYS */;
INSERT INTO `league` VALUES (1,"English Premier League",1),(2,"Championship",1),(3,"Allsvenskan",2),(4,"La Liga", 3),(5,"Seria A", 4), (6, "Ligue 1",5);
/*!40000 ALTER TABLE `league` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `club_league`
--
DROP TABLE IF EXISTS `club_league`;
CREATE TABLE `club_league`(
    `league_id` INTEGER NOT NULL,
    `club_id` INTEGER NOT NULL,
    `year` int(11) NOT NULL,
    FOREIGN KEY (`league_id`) REFERENCES league (`id`) ON DELETE RESTRICT ON UPDATE CASCADE,
    FOREIGN KEY (`club_id`) REFERENCES club (`id`) ON DELETE RESTRICT ON UPDATE CASCADE,
    PRIMARY KEY (league_id, club_id)
)ENGINE=InnoDB DEFAULT CHARSET=latin1;


--
-- Dumping data for table `club_league`
--
LOCK TABLES `club_league` WRITE;
/*!40000 ALTER TABLE `club_league` DISABLE KEYS */;
INSERT INTO `club_league` VALUES (1,1,2000),(2,1,1999),(3,2,2003),(4,3, 2006),(5,4, 1988), (6,5, 1989);
/*!40000 ALTER TABLE `club_league` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `player`
--
DROP TABLE IF EXISTS `player`;
CREATE TABLE `player`(
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `club_id` int(11) DEFAULT NULL,
    `first_name` varchar(100) NOT NULL,
    `last_name` varchar(100) NOT NULL,
    `country_id` int(11) NOT NULL,
    `fee` int(11) NOT NULL DEFAULT 0,
    `market_value` int(11) NOT NULL DEFAULT 0,
    PRIMARY KEY (`id`),
    CONSTRAINT `player_club` FOREIGN KEY (`club_id`) REFERENCES `club` (`id`) ON DELETE SET NULL ON UPDATE CASCADE, 
    CONSTRAINT `player_country` FOREIGN KEY (`country_id`) REFERENCES `country` (`id`)
)ENGINE=InnoDB DEFAULT CHARSET=latin1;



--
-- Dumping data for table `player`
--

LOCK TABLES `player` WRITE;
/*!40000 ALTER TABLE `player` DISABLE KEYS */;
INSERT INTO `player` VALUES 
(1,1,"Zlatan", "Ibrahimovic", 2, 1000000, 15000000),
(2,1,"Harry", "Kane", 1, 10, 50000),
(3,2,"Thierry", "Henry", 5, 9999, 150),
(4,2,"Robin", "Van Persie", 3, 1000, 3000);
/*!40000 ALTER TABLE `player` ENABLE KEYS */;
UNLOCK TABLES;

