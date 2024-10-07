/* Configuration needed by boot process
 *
 */

/* xVM class: debug */
#define XVM_CFG_VMDEBUG_SHOWWRITELOGS false /* Show logs while writing bootloader to memory */
#define XVM_CFG_VMDEBUG_SHOWINSTRUCTION false /* Show instruction that's about to execute */
#define XVM_CFG_VMDEBUG_SHOWCASEINSTRUCTION true /* Show instruction that's about to execute but in switch statement */

/* xVM class: show error logs */
#define XVM_CFG_VMLOGS_SHOWERRORS true /* Show runtime errors */

/* xVM class: show info logs */
#define XVM_CFG_VMLOGS_SHOWFAILINFO true /* Show instruction fail info */

/* Pre-boot configuration */
#define XVM_CFG_PREBOOT_SHOWLOGS true /* Show logs before and after writing bootloader to memory */