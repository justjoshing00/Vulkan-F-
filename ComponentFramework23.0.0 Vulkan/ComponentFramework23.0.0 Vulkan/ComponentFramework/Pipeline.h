#pragma once
#include <vulkan/vulkan.h>
#include <string>

//helper functions for creating the pipeline

auto CreatePipeLineinfo(VkStructureType stype_, VkShaderStageFlagBits stage_, VkShaderModule module_, const char* pName_)
{
    VkPipelineShaderStageCreateInfo result{};
    result.sType = stype_;
    result.stage = stage_;
    result.module = module_;
    result.pName = pName_;
    return result;
}
