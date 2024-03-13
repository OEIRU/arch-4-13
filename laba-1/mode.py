#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import itertools
def comb(m, n):
    for x in itertools.combinations(m, n):
        print(x)

