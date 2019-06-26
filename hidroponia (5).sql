-- phpMyAdmin SQL Dump
-- version 4.2.11
-- http://www.phpmyadmin.net
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 26-06-2019 a las 02:04:47
-- Versión del servidor: 5.5.40
-- Versión de PHP: 5.5.19

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de datos: `hidroponia`
--
CREATE DATABASE IF NOT EXISTS `hidroponia` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `hidroponia`;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `horas`
--

DROP TABLE IF EXISTS `horas`;
CREATE TABLE IF NOT EXISTS `horas` (
`idhoras` int(11) NOT NULL,
  `descr` varchar(45) DEFAULT NULL,
  `hora` time DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `horas`
--

INSERT INTO `horas` (`idhoras`, `descr`, `hora`) VALUES
(1, '5am', '05:00:00'),
(2, '6am', '06:00:00'),
(3, '7am', '07:00:00'),
(4, '8am', '08:00:00'),
(5, '5pm', '17:00:00'),
(6, '6pm', '18:00:00'),
(7, '7pm', '19:00:00');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `insumos`
--

DROP TABLE IF EXISTS `insumos`;
CREATE TABLE IF NOT EXISTS `insumos` (
`idinsumos` int(11) NOT NULL,
  `descr` varchar(45) DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `insumos`
--

INSERT INTO `insumos` (`idinsumos`, `descr`) VALUES
(1, 'Abono Universal Generico'),
(2, '  Abono Rosales'),
(3, 'Abono Plantas Verdes'),
(4, 'Abono Citricos'),
(5, 'Abono Hortencias');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `plantas`
--

DROP TABLE IF EXISTS `plantas`;
CREATE TABLE IF NOT EXISTS `plantas` (
`idplantas` int(11) NOT NULL,
  `descr` varchar(45) DEFAULT NULL,
  `idtplanta` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `plantas`
--

INSERT INTO `plantas` (`idplantas`, `descr`, `idtplanta`) VALUES
(1, 'Tomate', 4),
(2, '  Aji dulce', 4);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `plantas_insumos`
--

DROP TABLE IF EXISTS `plantas_insumos`;
CREATE TABLE IF NOT EXISTS `plantas_insumos` (
`idplantainsumo` int(11) NOT NULL,
  `idinsumos` int(11) NOT NULL,
  `idtplanta` int(11) NOT NULL,
  `cantidad` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `reporte`
--

DROP TABLE IF EXISTS `reporte`;
CREATE TABLE IF NOT EXISTS `reporte` (
`idreporte` int(11) NOT NULL,
  `hum` double DEFAULT '0',
  `temp` double DEFAULT '0',
  `hsuelo1` double DEFAULT '0',
  `hsuelo2` double DEFAULT '0',
  `hsuelo3` double DEFAULT '0',
  `fecha` datetime DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=103 DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `reporte`
--

INSERT INTO `reporte` (`idreporte`, `hum`, `temp`, `hsuelo1`, `hsuelo2`, `hsuelo3`, `fecha`) VALUES
(1, 86, 23, 11, 0, 0, '2019-05-26 02:32:45'),
(2, 87, 24, 11, 0, 0, '2019-05-26 02:32:50'),
(3, 86, 24, 11, 0, 0, '2019-05-26 02:32:56'),
(4, 87, 24, 12, 0, 0, '2019-05-26 02:33:01'),
(5, 87, 24, 14, 0, 0, '2019-05-26 02:33:06'),
(6, 87, 24, 12, 0, 0, '2019-05-26 02:33:12'),
(7, 86, 24, 14, 0, 0, '2019-05-26 02:33:17'),
(8, 0, 0, 0, 0, 0, '2019-06-11 10:26:30'),
(9, 0, 0, 0, 0, 0, '2019-06-11 10:26:37'),
(10, 0, 0, 0, 0, 0, '2019-06-11 10:26:45'),
(11, 0, 0, 0, 0, 0, '2019-06-11 10:26:52'),
(12, 0, 0, 0, 0, 0, '2019-06-11 10:27:00'),
(13, 0, 0, 0, 0, 0, '2019-06-11 10:27:07'),
(14, 0, 0, 0, 0, 0, '2019-06-11 10:27:15'),
(15, 0, 0, 0, 0, 0, '2019-06-11 10:27:22'),
(16, 0, 0, 0, 0, 0, '2019-06-11 10:27:30'),
(17, 0, 0, 0, 0, 0, '2019-06-11 10:27:37'),
(18, 0, 0, 0, 0, 0, '2019-06-11 10:27:45'),
(19, 0, 0, 0, 0, 0, '2019-06-11 10:27:52'),
(20, 0, 0, 0, 0, 0, '2019-06-11 10:28:00'),
(21, 0, 0, 0, 0, 0, '2019-06-11 10:28:07'),
(22, 0, 0, 0, 0, 0, '2019-06-11 10:28:15'),
(23, 0, 0, 0, 0, 0, '2019-06-11 10:28:22'),
(24, 0, 0, 0, 0, 0, '2019-06-11 10:28:30'),
(25, 0, 0, 0, 0, 0, '2019-06-11 10:28:37'),
(26, 0, 0, 0, 0, 0, '2019-06-11 10:28:45'),
(27, 0, 0, 0, 0, 0, '2019-06-11 10:28:52'),
(28, -2147483648, 0, 7, 0, 8, '2019-06-11 10:29:51'),
(29, -2147483648, 0, 99, 100, 97, '2019-06-11 10:29:59'),
(30, -2147483648, 0, 0, 0, 2, '2019-06-11 10:30:06'),
(31, -2147483648, 0, 72, 82, 75, '2019-06-11 10:30:14'),
(32, -2147483648, 0, 7, 13, 14, '2019-06-11 10:30:22'),
(33, -2147483648, 0, 35, 44, 42, '2019-06-11 10:30:29'),
(34, -2147483648, 0, 0, 0, 0, '2019-06-11 10:30:37'),
(35, -2147483648, 0, 100, 100, 100, '2019-06-11 10:30:44'),
(36, -2147483648, 0, 0, 0, 0, '2019-06-11 10:30:52'),
(37, -2147483648, 0, 100, 100, 100, '2019-06-11 10:30:59'),
(38, -2147483648, 0, 0, 0, 0, '2019-06-11 10:31:06'),
(39, -2147483648, 0, 55, 62, 60, '2019-06-11 10:31:14'),
(40, 87, 28, 27, 17, 24, '2019-06-11 10:31:21'),
(41, 77, 30, 0, 0, 0, '2019-06-11 10:31:29'),
(42, 77, 30, 88, 82, 81, '2019-06-11 10:31:36'),
(43, 77, 30, 1, 6, 8, '2019-06-11 10:31:44'),
(44, 77, 30, 97, 100, 96, '2019-06-11 10:31:51'),
(45, 77, 30, 36, 23, 26, '2019-06-11 10:31:59'),
(46, 77, 30, 39, 47, 45, '2019-06-11 10:32:06'),
(47, 77, 30, 46, 58, 56, '2019-06-11 10:32:14'),
(48, 77, 30, 4, 10, 12, '2019-06-11 10:32:22'),
(49, 77, 30, 66, 55, 56, '2019-06-11 10:32:30'),
(50, 77, 30, 100, 98, 97, '2019-06-11 10:32:38'),
(51, 77, 30, 95, 91, 90, '2019-06-11 10:32:46'),
(52, 77, 30, 0, 0, 0, '2019-06-11 10:32:54'),
(53, 77, 30, 0, 0, 0, '2019-06-11 10:33:02'),
(54, 77, 30, 2, 0, 5, '2019-06-11 10:33:10'),
(55, 77, 30, 99, 95, 94, '2019-06-11 10:33:18'),
(56, 77, 30, 3, 0, 3, '2019-06-11 10:33:26'),
(57, 77, 30, 0, 0, 0, '2019-06-11 10:33:34'),
(58, 76, 30, 100, 100, 100, '2019-06-11 10:33:42'),
(59, 76, 30, 0, 0, 0, '2019-06-11 10:33:50'),
(60, 76, 30, 0, 0, 0, '2019-06-11 10:33:58'),
(61, 76, 30, 100, 100, 100, '2019-06-11 10:34:06'),
(62, 76, 30, 0, 5, 6, '2019-06-11 10:34:14'),
(63, 75, 30, 47, 38, 42, '2019-06-11 10:34:22'),
(64, 75, 30, 100, 100, 100, '2019-06-11 10:34:30'),
(65, 75, 30, 10, 1, 10, '2019-06-11 10:34:38'),
(66, 74, 30, 54, 45, 48, '2019-06-11 10:34:46'),
(67, 74, 30, 100, 100, 100, '2019-06-11 10:34:54'),
(68, 75, 30, 100, 100, 100, '2019-06-11 10:35:02'),
(69, 75, 30, 100, 100, 100, '2019-06-11 10:35:10'),
(70, 75, 30, 100, 100, 100, '2019-06-11 10:35:18'),
(71, 76, 30, 0, 0, 0, '2019-06-11 10:35:26'),
(72, 76, 30, 26, 28, 38, '2019-06-11 10:35:34'),
(73, -2147483648, 0, 97, 100, 100, '2019-06-11 10:39:40'),
(74, -2147483648, 0, 100, 100, 100, '2019-06-11 10:39:49'),
(75, 75, 30, 97, 100, 100, '2019-06-11 10:51:08'),
(76, 74, 30, 100, 100, 100, '2019-06-11 10:51:16'),
(77, 74, 30, 47, 35, 37, '2019-06-11 10:51:23'),
(78, 74, 30, 55, 39, 46, '2019-06-11 10:51:31'),
(79, 74, 30, 0, 0, 0, '2019-06-11 10:51:38'),
(80, 74, 30, 0, 0, 0, '2019-06-11 10:51:46'),
(81, 74, 30, 0, 0, 2, '2019-06-11 10:51:54'),
(82, 74, 30, 0, 0, 0, '2019-06-11 10:52:10'),
(83, 74, 30, 100, 100, 100, '2019-06-11 10:52:18'),
(84, 73, 30, 26, 38, 39, '2019-06-11 10:52:26'),
(85, 73, 30, 55, 71, 67, '2019-06-11 10:52:34'),
(86, 73, 30, 100, 100, 100, '2019-06-11 10:52:43'),
(87, 74, 30, 0, 6, 8, '2019-06-11 10:52:51'),
(88, 74, 30, 0, 0, 0, '2019-06-11 10:52:59'),
(89, 73, 30, 100, 100, 100, '2019-06-11 10:53:07'),
(90, 73, 30, 0, 0, 0, '2019-06-11 10:53:15'),
(91, 73, 30, 86, 100, 89, '2019-06-11 10:53:23'),
(92, 73, 30, 4, 0, 0, '2019-06-11 10:53:31'),
(93, 74, 30, 0, 0, 0, '2019-06-11 10:53:39'),
(94, 74, 30, 0, 0, 0, '2019-06-11 10:53:47'),
(95, 74, 30, 37, 21, 25, '2019-06-11 10:53:55'),
(96, 74, 30, 58, 43, 44, '2019-06-11 10:54:03'),
(97, 74, 30, 93, 81, 79, '2019-06-11 10:54:12'),
(98, 74, 30, 0, 5, 0, '2019-06-11 10:54:20'),
(99, 74, 30, 0, 0, 0, '2019-06-11 10:54:28'),
(100, 74, 30, 100, 100, 100, '2019-06-11 10:54:36'),
(101, 75, 30, 100, 100, 100, '2019-06-11 10:54:44'),
(102, 75, 30, 0, 0, 0, '2019-06-11 10:54:52');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `sembrio`
--

DROP TABLE IF EXISTS `sembrio`;
CREATE TABLE IF NOT EXISTS `sembrio` (
`idsembrio` int(11) NOT NULL,
  `idplanta` int(11) NOT NULL,
  `fecha` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tplanta`
--

DROP TABLE IF EXISTS `tplanta`;
CREATE TABLE IF NOT EXISTS `tplanta` (
`idtplanta` int(11) NOT NULL,
  `descr` varchar(45) DEFAULT NULL,
  `temp` double DEFAULT NULL,
  `hum` double DEFAULT NULL,
  `triego` int(11) DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `tplanta`
--

INSERT INTO `tplanta` (`idtplanta`, `descr`, `temp`, `hum`, `triego`) VALUES
(1, 'citrico', 30, 60, 5),
(2, 'legunmbres', 31, 70, 10),
(3, 'hortalizas', 29, 80, 10),
(4, 'vegetales', 30, 80, 10);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `usuario`
--

DROP TABLE IF EXISTS `usuario`;
CREATE TABLE IF NOT EXISTS `usuario` (
`idusuario` int(11) NOT NULL,
  `nom` varchar(45) DEFAULT NULL,
  `ape` varchar(45) DEFAULT NULL,
  `dni` varchar(45) DEFAULT NULL,
  `pass` varchar(45) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `horas`
--
ALTER TABLE `horas`
 ADD PRIMARY KEY (`idhoras`);

--
-- Indices de la tabla `insumos`
--
ALTER TABLE `insumos`
 ADD PRIMARY KEY (`idinsumos`);

--
-- Indices de la tabla `plantas`
--
ALTER TABLE `plantas`
 ADD PRIMARY KEY (`idplantas`), ADD KEY `fk_plantas_tplanta_idx` (`idtplanta`);

--
-- Indices de la tabla `plantas_insumos`
--
ALTER TABLE `plantas_insumos`
 ADD PRIMARY KEY (`idplantainsumo`), ADD KEY `fk_plantas_has_insumos_insumos1_idx` (`idinsumos`), ADD KEY `fk_plantas_insumos_tplanta1_idx` (`idtplanta`);

--
-- Indices de la tabla `reporte`
--
ALTER TABLE `reporte`
 ADD PRIMARY KEY (`idreporte`);

--
-- Indices de la tabla `sembrio`
--
ALTER TABLE `sembrio`
 ADD PRIMARY KEY (`idsembrio`);

--
-- Indices de la tabla `tplanta`
--
ALTER TABLE `tplanta`
 ADD PRIMARY KEY (`idtplanta`);

--
-- Indices de la tabla `usuario`
--
ALTER TABLE `usuario`
 ADD PRIMARY KEY (`idusuario`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `horas`
--
ALTER TABLE `horas`
MODIFY `idhoras` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=8;
--
-- AUTO_INCREMENT de la tabla `insumos`
--
ALTER TABLE `insumos`
MODIFY `idinsumos` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT de la tabla `plantas`
--
ALTER TABLE `plantas`
MODIFY `idplantas` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT de la tabla `plantas_insumos`
--
ALTER TABLE `plantas_insumos`
MODIFY `idplantainsumo` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT de la tabla `reporte`
--
ALTER TABLE `reporte`
MODIFY `idreporte` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=103;
--
-- AUTO_INCREMENT de la tabla `sembrio`
--
ALTER TABLE `sembrio`
MODIFY `idsembrio` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT de la tabla `tplanta`
--
ALTER TABLE `tplanta`
MODIFY `idtplanta` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT de la tabla `usuario`
--
ALTER TABLE `usuario`
MODIFY `idusuario` int(11) NOT NULL AUTO_INCREMENT;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
