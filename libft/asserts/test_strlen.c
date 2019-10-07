#include <libft.h>
#include <stddef.h>
#include <criterion.h>
#include <criterion/theories.h>

size_t      ft_strlen(const char *s) {
    const char *s2 = s;

    while (*s2 != '\0')
        ++s2;
    return (s2 - s);
}

TheoryDataPoints(libc_functions, test_strlen) = {
	DataPoints(char*, "test", "", NULL, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. In libero ipsum, suscipit et lacus vel, lacinia commodo lorem. Cras cursus, nibh in imperdiet ultrices, nisl sem molestie arcu, eget rutrum justo arcu in purus. Morbi ac dignissim ipsum. Morbi sed est justo. Maecenas euismod tincidunt purus, et malesuada mi sollicitudin vitae. Donec vehicula nisl scelerisque, tincidunt arcu ultrices, scelerisque felis. Nunc suscipit lorem et blandit lobortis. Nullam auctor tincidunt nibh eu pulvinar. Morbi metus tellus, finibus non finibus non, feugiat id sapien. Morbi fermentum turpis a egestas posuere. Donec bibendum ante a risus blandit, eget efficitur orci dignissim. Vestibulum tempor, tellus eu dapibus ullamcorper, neque elit tempus risus, id dignissim ligula massa porta diam. Ut nisl magna, scelerisque at aliquam ac, ultrices ac nunc.\n\nPraesent odio risus, finibus ut fringilla ac, bibendum pretium massa. Proin eget finibus ex, eu semper arcu. Morbi mattis, turpis eu laoreet sodales, ante augue porta magna, eget sodales eros lacus ac erat. Nulla facilisi. In euismod, augue at mollis ultricies, diam massa sagittis quam, id pretium leo risus quis ipsum. Vestibulum lacus est, scelerisque at mi et, facilisis semper dui. Morbi vel metus at turpis viverra ultricies nec in libero. Suspendisse dignissim convallis vehicula. Nulla mollis, sapien quis facilisis vulputate, eros nisl accumsan leo, et vulputate risus urna a dolor. Donec egestas facilisis diam, et fermentum nibh placerat a. Vivamus vitae elementum ex. Vivamus aliquet metus vulputate varius pharetra. Vivamus finibus nisl sem, nec cursus nibh condimentum et. Suspendisse sed neque in odio dictum accumsan at nec ante. Integer imperdiet quam non tortor dignissim ornare.\n\nCras condimentum dui malesuada, iaculis lacus eu, auctor justo. Sed eu augue arcu. Morbi at consequat risus. Pellentesque fringilla euismod est, eget ullamcorper odio consectetur eu. Nulla tortor nulla, ultrices a lacus eget, tincidunt fringilla elit. Donec nunc purus, pellentesque vitae ligula eget, porta volutpat ex. Cras in felis quis dolor finibus volutpat in at est. Pellentesque tincidunt iaculis facilisis. Nulla facilisi. Proin sed aliquet odio, ac dictum erat. Sed dapibus, ipsum ac molestie consequat, tortor nisl iaculis dolor, sit amet tincidunt risus urna ut lorem. Quisque non orci vitae neque tristique porttitor ac vitae ligula.\n\nIn lectus est, consectetur sed mattis ac, pretium ultricies justo. Duis at luctus urna. Quisque mollis lorem id facilisis interdum. Praesent lobortis felis risus, a ultrices orci accumsan ut. Vestibulum sit amet risus posuere, maximus urna in, finibus est. Aliquam erat volutpat. Suspendisse id nisi vitae magna volutpat pulvinar eu vitae lectus. Etiam blandit maximus eros, ut fringilla metus tempus ut. Nullam scelerisque libero eget tortor hendrerit mollis. Fusce placerat turpis vitae lectus tincidunt, in laoreet eros elementum. Sed eu metus posuere, porta ante non, aliquet lorem.\n\nInteger congue, orci sit amet consectetur ultricies, diam eros pretium leo, id suscipit risus metus ut mi. Phasellus non mattis tellus, sit amet bibendum erat. Etiam in sem quam. Donec tristique, elit a dignissim vehicula, sapien mauris fermentum lorem, convallis rutrum libero ex at lectus. Nullam enim mauris, vestibulum nec posuere vel, iaculis ut risus. Proin non tortor et tortor gravida blandit. Aliquam faucibus semper eros, sit amet scelerisque augue efficitur id. Cras pulvinar ligula sed nisl blandit sodales. Aliquam purus turpis, hendrerit et purus vitae, semper gravida tellus. Cras lorem arcu, fermentum a convallis sed, volutpat non erat. Integer vulputate malesuada leo vitae blandit. Nam varius, lectus vehicula vehicula sodales, nisl elit eleifend nisi, venenatis tempor nulla nunc et turpis. Quisque consequat eget libero id malesuada. Donec risus felis, ultricies at dolor ut, eleifend mollis mi.\n\nCras tempor orci id erat lacinia fringilla. Curabitur lacus ligula, rhoncus non cursus in, cursus ac mi. Vestibulum pharetra eros magna, et vehicula est varius a. Sed vitae ornare libero, nec tristique ligula. In ut mauris nec magna dignissim finibus eget in nibh. Nulla iaculis est auctor, blandit massa ac, lacinia diam. Nunc auctor ipsum ligula. Quisque tempor quam quis augue mattis auctor. Fusce consectetur, ante vitae semper varius, nibh lectus varius nisi, ac pulvinar nibh lorem in turpis. Aliquam aliquam enim a sem aliquam, vitae egestas sapien lacinia. Pellentesque sem eros, aliquam sit amet metus ut, commodo feugiat leo.\n\nDuis ac accumsan eros, sit amet dictum metus. Phasellus non posuere eros. Praesent eu commodo justo. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Curabitur at dignissim nulla, ac pulvinar ante. Etiam et nulla vel est aliquam porttitor et et eros. Sed augue nunc, volutpat sit amet magna nec, vehicula facilisis sapien. Aliquam aliquet viverra orci, eget aliquam dui varius ac. Aliquam id diam ut orci ultricies rhoncus vitae ut metus. Morbi dui quam, congue vel augue sed, bibendum pharetra tellus. Phasellus tempus aliquet velit ac rhoncus.\n\nLorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus ante tortor, iaculis sit amet nisi vestibulum, suscipit pulvinar purus. Aenean aliquam arcu at arcu gravida imperdiet. Aenean blandit mauris vitae metus venenatis ornare. Proin venenatis id sem et fringilla. Integer porta risus in feugiat hendrerit. Suspendisse a odio pulvinar, bibendum felis at, molestie nunc. Maecenas eu interdum metus. Nullam dictum enim ac nibh maximus volutpat. Mauris convallis augue lacinia, pharetra mi a, pulvinar metus. Aenean eu tincidunt quam. Suspendisse vehicula turpis ac sollicitudin placerat. Phasellus sagittis eros vel nisl posuere pellentesque. Sed ac feugiat massa, ut cursus mauris. Proin cursus, mauris sed aliquet dapibus, tellus purus tempus arcu, a accumsan odio nunc sed sapien.\n\nNulla sapien turpis, placerat eu laoreet at, bibendum varius orci. Nullam hendrerit tincidunt mauris ac mollis. Phasellus in tincidunt tellus. Vivamus euismod lacus est, quis pretium velit rhoncus interdum. Vestibulum sit amet ipsum sollicitudin, bibendum est at, faucibus ex. Cras vehicula, magna nec blandit tempus, augue quam condimentum velit, eget placerat elit enim feugiat metus. Ut dictum arcu a imperdiet tempor. Ut in orci a urna suscipit porta. Mauris euismod dui lectus, sit amet hendrerit neque rhoncus in. Proin egestas mauris in nisl tincidunt posuere. Suspendisse ut orci ante. Curabitur posuere placerat sapien id mattis.\n\nCurabitur consequat, lorem eu iaculis eleifend, felis est laoreet justo, et dapibus massa ante et lorem. Pellentesque nec dolor ligula. Phasellus vel ipsum vitae diam porttitor pretium. Pellentesque dictum, dui sed accumsan vehicula, erat lacus ornare sem, ut fermentum risus nulla vitae erat. Vivamus sed rutrum elit. Pellentesque blandit posuere velit, in rutrum nibh laoreet quis. Donec faucibus leo massa, eu dapibus sem dictum et. Phasellus euismod dolor vel mi convallis, et pharetra lorem aliquet. Maecenas cursus, nunc eu vestibulum porttitor, elit leo pulvinar velit, vitae ultricies enim neque quis magna. Cras eu finibus dolor. In facilisis, nisl nec egestas consequat, erat nulla ultrices est, et eleifend est lectus eget libero.")
};

Theory((char *str), libc_functions, test_strlen) {
    cr_assume(str[0] == str[0]);
    cr_assert_eq(ft_strlen(str), strlen(str));
};