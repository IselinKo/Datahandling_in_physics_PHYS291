## this file converts raw data .nii file to text file .cvs

import nibabel as nib
import csv

file_path = r"\Users\ikong\OneDrive\Documents\Fysikk Master\Vår 2026\PHYS291\data\rfMRI_REST1_LR_hp2000_clean_rclean_tclean.nii"

img = nib.load(file_path)
data = img.get_fdata()

x_dim, y_dim, z_dim, t_dim = data.shape

with open("fmri_val1_t42.csv", "w", newline="") as f:

    writer = csv.writer(f)
    writer.writerow(["x","y","z","t","intensity"])


    for t in range(42):

        print("Processing t =", t)

        for x in range(0, x_dim, 2):   # downsampling, only extract every 2 of the datapoints
            for y in range(0, y_dim, 2):
                for z in range(0, z_dim, 2):

                    val = data[x,y,z,t]

                    # Skip background and then some
                    if abs(val) < 1:
                        continue

                    writer.writerow([x,y,z,t,val])

print("Done.")