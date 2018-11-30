---
title: 'rdbsp: A rock dynamic behavior simulation program'
tags:
  - rock
  - dynamic behavior
  - forward Euler
authors:
 - name: Zhang Ning
   orcid: 0000-0003-3597-0691
   affiliation: "1"
affiliations:
 - name: Nanjing Unversity of Science and Technology
   index: 1
date: 30 November 2018
bibliography: paper.bib
---

# Summary

Rock dynamics has become one of the most important topics in the field of rock mechanics and rock engineering. The spectrum of rock dynamic behavior widely includes phenomena of rockbursting, spalling, popping, collapse, toppling, sliding, and so on, which induced by the stress redistribution and energy release after excavation [@aydan2017rock]. The version of rdbsp arms to simulate the process of displacement field redistribution and stress wave propagation in deep underground rock with finite element method[@WANG201547]. Forward Euler time integration scheme is adapted in this program to simulate the dynamic procedure [@Ascher1994]. The elastic constitutive model and Mohr-Coulomb plastic model are implemented in this version [@ottosen2005mechanics]. 

To speed up the simulation as well as overcome the over-stiff effect of fully integrated element during dynamic simulation [@zienkiewicz2013finite], Three-dimensional solid element type with a single integration point is implemented. 
As zero energy modes so called hourglass effect could be happeaned for single point integrated element, .
To eliminate the hourglass effect in calculation, the hourglass resistance, which is perpendicular to the rotation modal of rigid body and established by Belytschkoand Flanagan in 1982, is applied in this program (Belytschko etal., 1982). 

The Jaumann derivative is added into the program with the concern of the effect of the rigid body rotation to solve the difficulty of the large deformation calculation for the deep rock mass (Valanis, 1990).


The program enables both the static and the dynamic finite element calculation. The geometric model can be built by the Hypermesh pre-processing software via the keyword recognition and post-processing interfaces, and the calculated result can be shown by the two post-processing programs Tecplot or Paraview. 

Material, input interpreate, memory control model, index map

The working flow of rdbsp is showin in the figure.

Two tests file are included in the files

# Acknowledgement
Supported by "the Fundamental Research Funds for the Central Universities"(No. 30917011337) and "the program of China Scholarships Council" (No. 201806845032)


# References
