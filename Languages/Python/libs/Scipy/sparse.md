# Sparse.matrix
```
import numpy as np
from scipy import sparse
```
## lil matrix
```
row_ind=np.array([0,1,2,3,4])
col_ind=np.array([4,3,2,1,0])
data=np.ones(5)
coo_mat = sparse.coo_matrix((data, (row_ind, col_ind)));
# print(coo_mat)
# print(coo_mat.todense()==coo_mat.toarray()) #! True

lil_mat = sparse.lil_matrix((([0],[1],[2]),([1],[1],[1])))
print(lil_mat)
```
## csr_matrix
```
mat_dense = np.array(
      [[1., 0., 0., 0., 0.],
       [0., 0., 2., 0., 3.],
       [0., 0., 0., 0., 0.],
       [0., 0., 0., 4., 0.],
       [0., 0., 0., 0., 5.]])
mat_csc = sparse.csc_matrix(mat_dense)
```
mat_csc.data stores the data of sparse matrix
mat_csc.indices # row indices for each column, same shape with data
mat_csc.indptr # slices for data, same dim with column